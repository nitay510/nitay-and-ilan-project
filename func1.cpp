#include "func1.h"
#include <vector>
func1::func1(HoldInfo* inf){
  this->inf = inf;
}
std::string func1::getDesctiption(){
  return this->description;
}
void func1::execute() {
  this->inf->write("Please upload your local train CSV file.");
 while(!this->inf->read().empty()) {
     //cout <<this->inf->read()<< endl;
  }

}
