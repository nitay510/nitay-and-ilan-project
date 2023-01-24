#include "func3.h"

func3::func3(HoldInfo* inf){
  this->inf = inf;
}
std::string func3::getDesctiption(){
  return this->description;
}
void func3::execute() {
if(inf->haveFiles()){
  int i = 1;
  std::list<std::string> predictList;
  for (auto & currentVector : this->inf->getTestFile()) {
  predictList.push_back(this->inf->predictWithK(currentVector));
 // std::cout << this->inf->predictWithK(currentVector) << '\n';
  i++;
}
this->inf->setPredict(predictList);
this->inf->write("classifying data complete\n");
std::this_thread::sleep_for(std::chrono::milliseconds(10));
} else
  this->inf->write("please upload data\n");
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
}
