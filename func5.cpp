#include "func5.h"
func5::func5(HoldInfo* inf){
  this->inf = inf;
}
std::string func5::getDesctiption(){
  return this->description;
}
void func5::execute() {
    cout<<"func5 is working"<<endl;
}
