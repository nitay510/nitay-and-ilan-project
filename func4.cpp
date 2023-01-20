#include "func4.h"

func4::func4(HoldInfo* inf){
  this->inf = inf;
}
std::string func4::getDesctiption(){
  return this->description;
}
void func4::execute() {
    cout<<"func4 is working"<<endl;
}
