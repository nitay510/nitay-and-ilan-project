#include "DefultIO.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
//a class for Mankovski distance
class SocketIO : public DefultIO {
int client_sock;
public:
  SocketIO(int client_sock);
  virtual std::string read () override;
  virtual void write(std::string s1) override;
};
