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
  std::map<int,std::string> predictList;
  for (auto & currentVector : this->inf->getTestFile()) {
  predictList.insert(std::pair<int,std::string>(i,this->inf->predictWithK(currentVector)));
  i++;
}
this->inf->setPredict(predictList);
this->inf->write("classifying data complete\n");
std::this_thread::sleep_for(std::chrono::milliseconds(100));
} else
  this->inf->write("please upload data\n");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
