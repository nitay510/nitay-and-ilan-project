#include "KNN.h"
#include "CLI.h"
#include "DistancesFunc.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
//the server main get file place and read vectors from this file, than bind and accept clients,
//every client send string and the server make a vector,distance function, and k closest neghibers to read from
// than it send to the client which one is the closest acording to the k closest neghibers.
int main(int argc,char** argv) {
  //check if the number of arguments is enough.
    if(argc <= 1){
  std::cout << "you didn't put enough arguments!!:" << '\n';
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
    //start infinite loop of accepting clients
    while(true){
      //accept client
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        SocketIO sio(client_sock);
        CLI cli(&sio);
        cli.start();
}
}
