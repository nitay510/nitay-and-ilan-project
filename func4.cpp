#include "func4.h"
#include  <sstream>
func4::func4(HoldInfo* inf){
  this->inf = inf;
}
std::string func4::getDesctiption(){
  return this->description;
}
void func4::execute() {
  if(!this->inf->haveFiles()){
    this->inf->write("please upload data\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return;
  }
  if(!this->inf->classifyFiles()){
    this->inf->write("please classify the data\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return;
  }
    this->inf->write("start func 4");
    for(auto it=this->inf->getPredictList().begin(); it != this->inf->getPredictList().end(); it++){
      std::stringstream mapS;
      mapS << it->first << "  " << it->second << std::endl;
      this->inf->write(mapS.str());
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    this->inf->write("Done\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
