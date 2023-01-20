#include "func2.h"
#include  <sstream>
func2::func2(HoldInfo* inf){
  this->inf = inf;
}
std::string func2::getDesctiption(){
  return this->description;
}
void func2::execute() {
  std::stringstream current_k;
  current_k <<"The current KNN parameters are: K = "<< this->inf->getK() << ", distance metric = " << this->inf->getDName();
  std::string toSend = current_k.str();
  this->inf->write(toSend);
  std::string toRead = this->inf->read();
  
}
