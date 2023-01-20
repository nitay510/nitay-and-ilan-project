#include "func3.h"

func3::func3(HoldInfo* inf){
  this->inf = inf;
}
std::string func3::getDesctiption(){
  return this->description;
}
void func3::execute() {
    cout<<"func3 is working"<<endl;
}
