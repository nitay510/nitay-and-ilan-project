#include "func1.h"

func1::func1(HoldInfo* inf){
  this->inf = inf;
}
std::string func1::getDesctiption(){
  return this->description;
}
void func1::execute() {
  cout<<"func1 is working"<<endl;
}
