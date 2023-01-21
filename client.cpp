#include <iostream>
#include <fstream>
#include "DistancesFunc.h"
#include <sys/socket.h>
#include <sstream>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <thread>
#include <chrono>
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
              if(strcmp(buffer1,"close")==0) //if we want to end the program.
              break;
              else
              std::cout << buffer1 ;
            }
            // Get input from client

            if(!(buffer1[0]=='i'&&buffer1[1]=='n'&&buffer1[2]=='v'&&buffer1[3]=='a')){
            std::string input;
            std::getline(std::cin, input);
            // Send input to server
            int sent_bytes = send(sock, input.c_str(),input.length(), 0);
            //will need to check the sent_bytes
            //start read and send until the end of the function
          }
                    if(strcmp(buffer1,"Please upload your local train CSV file.")==0)
                    {
                    std::cout << buffer1 << '\n';
                    std::string localTrain;
                    std::getline(std::cin, localTrain);
                    std::ifstream file(localTrain);
                    std::string line;
                    if (file.is_open()) {
                       while (getline(file, line)) {
                           std::cout<<line<<std::endl;
                           int sent_bytes = send(sock, line.c_str(),line.length(), 0);
                           std::this_thread::sleep_for(std::chrono::seconds(1));
                        }
                    //   std::string stop="stop";
                      // int sent_bytes = send(sock, stop.c_str(),stop.length(), 0);
                        file.close();
                        break;
                    }
                    else {
                        std::cout << "Unable to open file";
                    }
                 }
                    }
        close(sock);
        return 0;
}
