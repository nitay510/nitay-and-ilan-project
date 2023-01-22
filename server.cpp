#include "KNN.h"
#include "CLI.h"
#include <thread>
#include <vector>
#include <cstring>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <queue>
#include <mutex>
#include <condition_variable>
const int NUM_THREADS = 1000;
std::queue<int> client_socks;
std::mutex mtx;
std::condition_variable cv;
std::vector<std::thread> threads;
bool stop = false;

void worker() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !client_socks.empty() || stop; });

        if (stop && client_socks.empty()) {
            break;
        }

        int client_sock = client_socks.front();
        client_socks.pop();
        lock.unlock();

        SocketIO* sio = new SocketIO(client_sock);
        CLI cli(sio);
        cli.start();
        delete sio;
    }
}

int main(int argc, char** argv) {
    //check if the number of arguments is enough.
    if (argc <= 1) {
        std::cout << "you didn't put enough arguments!!" << '\n';
        exit(1);
    }

    const int server_port = std::stoi(argv[1]);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        exit(1);
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    //bind
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        exit(1);
    }
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        exit(1);
    }

    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.push_back(std::thread(worker));
    }

    while (true) {
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        } else {
            std::unique_lock<std::mutex> lock(mtx);
            client_socks.push(client_sock);
            cv.notify_one();
        }
    }

    {
        std::unique_lock<std::mutex> lock(mtx);
        stop = true;
        cv.notify_all();
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
