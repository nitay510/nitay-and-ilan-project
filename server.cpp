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
std::queue<int> client_socks;
std::mutex mtx;
std::condition_variable cv;
bool stop = false;
//creating CLI and Socket to start the program
void worker(int client_sock) {
    SocketIO* sio = new SocketIO(client_sock);
    CLI cli(sio);
    cli.start();
    delete sio;
}

int main(int argc, char** argv) {
    //check if the number of arguments is enough.
    if (argc <= 1) {
        std::cout << "you didn't put enough arguments!!" << '\n';
        exit(1);
    }

    const int server_port = std::stoi(argv[1]);
    int sock = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
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
    if (listen(sock, SOMAXCONN) < 0) {
        perror("error listening to a socket");
        exit(1);
    }

    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
//in order to support several clients meanwhile
    while (true) {
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                continue;
            } else {
                perror("error accepting client");
            }
        } else {
            std::thread t(worker, client_sock);
            t.detach();
        }
    }
    close(sock);
    return 0;
}
