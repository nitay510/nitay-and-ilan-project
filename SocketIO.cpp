#include "SocketIO.h"
SocketIO::SocketIO(int client_sock){
  this->client_sock = client_sock;
}
std::string SocketIO::read() {
  char bufferRecive[4096];
  std::string sendString;
  bool invalidCheck = false;
  int expected_data_len = sizeof(bufferRecive);
  int read_bytes = recv(this->client_sock, bufferRecive, expected_data_len, 0);
  if (read_bytes <= 0)
      sendString = "failed reading";
  // if it was able to read it
  else
    sendString = bufferRecive;
    return sendString;
  }
  void SocketIO:: write(std::string s1){
    int data_len = s1.length()+1;//because of \n
    char * buffer = new char [data_len];
    strcpy(buffer,s1.c_str());
    int sent_bytes = send(this->client_sock,buffer, data_len, 0);
    delete [] buffer;
  }
