#include "HoldInfo.h"

HoldInfo::HoldInfo(DefultIO* dio){
  this->k = 5;
  std::list <std::vector<double>> testFile;
  this->dio = dio;
  this->dTypeName = "AUC";
  EucDistance d;
  this->dType = &d;
}
void HoldInfo::setKnn(std::multimap<std::vector<double>,std::string> LabledPoints){
  KNN knn1(LabledPoints);
  this->knn = &knn1;
}
void HoldInfo:: setDio(DefultIO* dio){
  this->dio = dio;
}
void HoldInfo:: setTestFile(std::list <std::vector<double>> testFile){
    this->testFile = testFile;
}

void HoldInfo:: setK(int k){
  this->k = k;
}
void HoldInfo::setdType(Distance* dType,std::string dTypeName){
  this->dTypeName = dTypeName;
  this->dType = dType;
}
std::string HoldInfo::predictWithK(std::vector<double> Point){
  return this->knn->predict(Point,this->dType,this->k);
}
int HoldInfo:: getK(){
  return this->k;
}
std::string HoldInfo:: getDName(){
  return this->dTypeName;
}
void HoldInfo::write(std::string str){
  this->dio->write(str);
}
std::string HoldInfo::read() {
  return this->dio->read();
}
