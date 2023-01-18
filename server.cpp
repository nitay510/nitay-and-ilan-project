#include "KNN.h"
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
    if(argc <= 2){
  std::cout << "you didn't put enough arguments!!:" << '\n';
  exit(1);
}
    //create multimap for the vectors in the file
    std::multimap<std::vector<double>, std::string> labledPoints;
    std::string fileName = argv[1];
    //start read vectors from file
    std::fstream file (fileName,std::ios::in);
    if(!file.is_open()){
      std::cout << "problem with opening the file" << '\n';
        exit(1);
    }
    std::string line;
    //read from the file
    while(getline(file, line))
  {
  // Read the next line from File until it reaches the end.
    std::vector<double> v;
    std::string word;
    std::stringstream is(line);
    double val;
    std::string name;
    int size;
    bool getSize=false;
    bool check = true;
    //read the  numbers and the name
    while(check) {
      getline(is, word, ',');
      check=checkIsDouble(word,val);
      if(check)
      v.push_back(val);
      else
      name = word;
      }
      //to get the size of first vector
      if(getSize==false){
        getSize=true;
        size=v.size();
      }
      //check if it was a valid vector if it does put it in the map
      if (is.rdbuf()->in_avail() != 0||v.size()!= size){
          std::cout << "the vector in the file wasnt good" << '\n';
            exit(1);
      }
      labledPoints.insert(std::pair<std::vector<double>, std::string>(v,name));
    }
    KNN myList(labledPoints);
    const int server_port = std::stoi(argv[2]);
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
        //start loop to read vectors from client until client stop and than break the loop
        while (true) {
            int k=0;
            std::string distanceMatrix;
            char bufferRecive[4096];
            bool invalidCheck = false;
            int expected_data_len = sizeof(bufferRecive);
            int read_bytes = recv(client_sock, bufferRecive, expected_data_len, 0);
            if (read_bytes == 0) {
                break;
            }
            else if (read_bytes < 0) {
                std::cout<<"failed reading"<<std::endl;
                break;
            }
            // if it was able to read it
            else {
              std::string sendString;
              std::string invalid = "invalid input";
              std::string word2;
              std::vector<double> v1;
              std::stringstream is1(bufferRecive);
              double val1;
              bool check = true;
            //make vectors from those lines
            while(check) {
              getline(is1, word2, ' ');
              check=checkIsDouble(word2,val1);
              if(check){
                // in case it have just numbers
              if (is1.rdbuf()->in_avail() == 0){
              invalidCheck = true;
              check = false;
            }
              v1.push_back(val1);
            }
            // we got to the place of the distance matrix name.
              else
                  distanceMatrix = word2;
            }
            if (!invalidCheck) {
            getline(is1, word2, ' ');
            if(checkIsDouble(word2,val1)){
            k = (int)val1;
            // if the k is to small
            if (k<=0)
              invalidCheck = true;
            }
            // if the k isnt a number
            else
              invalidCheck = true;
            }
              if (!invalidCheck) {
                //check which distance metrica to use
                if(distanceMatrix.compare("AUC")==0){
                EucDistance d;
                sendString = myList.predict(v1,&d,k);
              }
                else if(distanceMatrix.compare("MAN")==0){
                ManDistance d;
                sendString = myList.predict(v1,&d,k);
              }
                else if(distanceMatrix.compare("CHB")==0){
                CheDistance d;
                sendString = myList.predict(v1,&d,k);
              }
                else if(distanceMatrix.compare("CAN")==0){
                CanDistance d;
                sendString = myList.predict(v1,&d,k);
              }
                else if(distanceMatrix.compare("MIN")==0){
                MinDistance d;
                sendString = myList.predict(v1,&d,k).c_str();
                }
                // if the distance Marix isnt valid
                else{
                invalidCheck = true;
                }
              }
              // if something went wrong on the way
              if(invalidCheck)
              sendString = "invalid input";

            int sizeBites = sendString.length()+1;
            // crate char * to send
            char* bufferSend = new char[sizeBites];
            // copy to the char*
            strcpy(bufferSend,sendString.c_str());
            int sent_bytes = send(client_sock, bufferSend, sizeBites, 0);
            // delete the char*
            delete [] bufferSend;
            if (sent_bytes < 0) {
                perror("error sending to client");
            }
        }
    }
}
}
