#include "func2.h"
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
  if(strcmp(toRead.c_str(),"$")!=0) {
    std::istringstream is1(toRead);
    int newK;
    std::string newMetric;
    if(is1>>newK){
      if(newK>0){
      is1>>newMetric;
      if(newMetric.compare("AUC")==0){
        EucDistance* d = new EucDistance();
        this->inf->setdType(d,"AUC");
        this->inf->setK(newK);
      }
        else if(newMetric.compare("MAN")==0){
        ManDistance* d = new ManDistance();
        this->inf->setdType(d,"MAN");
        this->inf->setK(newK);
      }
        else if(newMetric.compare("CHB")==0){
        CheDistance* d = new CheDistance();
        this->inf->setdType(d,"CHB");
          this->inf->setK(newK);
      }
        else if(newMetric.compare("CAN")==0){
        CanDistance* d = new CanDistance();
        this->inf->setdType(d,"CAN");
          this->inf->setK(newK);
      }
        else if(newMetric.compare("MIN")==0){
        MinDistance* d = new MinDistance();
        this->inf->setdType(d,"MIN");
          this->inf->setK(newK);
        } else
          this->inf->write("invalid value for metric \n");
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    else
      this->inf->write("invalid value of k \n");
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
    else
    this->inf->write("invalid value of k \n");
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}
