#include <iostream>
#include "DistancesFunc.h"
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
// client main connect to a server than read input represen vector|distance func| k and send it to the server
// than get from the server the name of the closest one according to the closest k neghibers.
int main(int argc,char** argv) {
  //check if the number of arguments is enough.
    if(argc<=2){
  std::cout << "you didn't put enough arguments!!:" << '\n';
  exit(1);
}
    const char* ip_address =argv[1];
    const int port_no = std::stoi(argv[2]);
    //create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        exit(1);
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    //connect to the server
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
        exit(1);
    }
    bool check = true;
    // start infinite loop until client insert -1
    while(check){
      // read input from the client
        std::cout << "enter input" <<std::endl;
        std::string input1;
        std::getline(std::cin, input1);
        double val=0;
        checkIsDouble(input1,val);
        // if he want to close the program
        if(val==-1)
        break;
        int data_len = input1.length()+1;//because of \n
        char * buffer = new char [data_len];
        strcpy(buffer,input1.c_str());
        int sent_bytes = send(sock,buffer, data_len, 0);
        delete [] buffer;
        if (sent_bytes < 0) {
            std::cout<<"error sending message"<<std::endl;
            continue;
            }
        char buffer1[4096];
        int expected_data_len = sizeof(buffer1);
        int read_bytes = recv(sock, buffer1, expected_data_len, 0);
        if (read_bytes == 0) {
        std::cout<<"no bytes to read"<<std::endl;
            }
            else if (read_bytes < 0) {
            std::cout<<"failed reading"<<std::endl;
            }
            else {
                std::cout << buffer1 << std::endl;
            }
        }
        close(sock);
        return 0;
}
