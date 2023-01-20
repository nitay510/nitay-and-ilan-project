#include "func1.h"
#include <vector>
func1::func1(HoldInfo* inf){
  this->inf = inf;
}
std::string func1::getDesctiption(){
  return this->description;
}
void func1::execute() {
  cout<<"Please upload your local train CSV file."<<endl;
  this->inf->write("invoke func1");
 while(!this->inf->read().empty()) {
     //cout <<this->inf->read()<< endl;
  }

}
