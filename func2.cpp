#include "func2.h"
#include <thread>
#include  <sstream>
func2::func2(HoldInfo* inf){
  this->inf = inf;
}
std::string func2::getDesctiption(){
  return this->description;
}
void func2::execute() {
  std::stringstream current_k;
  current_k <<"The current KNN parameters are: K = "<< this->inf->getK() << ", distance metric = " << this->inf->getDName()<<"\n";
  std::string toSend = current_k.str();
  this->inf->write(toSend);
  std::string toRead = this->inf->read();
  if(!toRead.empty()) {
    std::istringstream is1(toRead);
    int newK;
    std::string newMetric;
    if(is1>>newK){
      if(newK>0){
      is1>>newMetric;
      if(newMetric.compare("AUC")==0){
        EucDistance d;
        this->inf->setdType(&d,"AUC");
        this->inf->setK(newK);
      }
        else if(newMetric.compare("MAN")==0){
        ManDistance d;
        this->inf->setdType(&d,"MAN");
        this->inf->setK(newK);
      }
        else if(newMetric.compare("CHB")==0){
        CheDistance d;
        this->inf->setdType(&d,"CHB");
          this->inf->setK(newK);
      }
        else if(newMetric.compare("CAN")==0){
        CanDistance d;
        this->inf->setdType(&d,"CAN");
          this->inf->setK(newK);
      }
        else if(newMetric.compare("MIN")==0){
        MinDistance d;
        this->inf->setdType(&d,"MIN");
          this->inf->setK(newK);
        } else
          this->inf->write("invalid value for metric \n");
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    else
      this->inf->write("invalid value of k \n");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
    else
    this->inf->write("invalid value of k \n");
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}
