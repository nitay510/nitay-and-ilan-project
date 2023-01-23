#include "HoldInfo.h"

HoldInfo::HoldInfo(DefultIO* dio){
  this->k = 5;
  std::list <std::vector<double>> testFile;
  this->dio = dio;
  this->dTypeName = "AUC";
  EucDistance* d= new EucDistance();
  this->dType = d;
  this->haveTestFile = false;
  this->haveFile = false;
  this->dataClassified = false;
}
void HoldInfo::setPredict(std::list<std::string> filesAfterPredict){
  this->filesAfterPredict = filesAfterPredict;
  this->dataClassified = true;
}
void HoldInfo::setKnn(std::multimap<std::vector<double>,std::string> LabledPoints){
  KNN* knn1 = new KNN(LabledPoints);
  this->knn = knn1;
  this->haveFile = true;
}
void HoldInfo:: setDio(DefultIO* dio){
  this->dio = dio;
}
void HoldInfo:: setTestFile(std::list <std::vector<double>> testFile){
    this->testFile = testFile;
    this->haveTestFile = true;
}

void HoldInfo:: setK(int k){
  this->k = k;
}
void HoldInfo::setdType(Distance* dType,std::string dTypeName){
  delete(this->dType);
  this->dTypeName = dTypeName;
  this->dType = dType;
}
std::string HoldInfo::predictWithK(std::vector<double> Point){
  return this->knn->predict(Point,this->dType,this->k);
}
std::list<std::string> HoldInfo::getPredictList(){
  return this->filesAfterPredict;
}
std::list <std::vector<double>> HoldInfo::getTestFile(){
  return this->testFile;
}
int HoldInfo:: getK(){
  return this->k;
}
KNN* HoldInfo:: getKNN(){
  return this->knn;
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
bool HoldInfo::haveFiles(){
  return(this->haveFile&&this->haveTestFile);
}
bool HoldInfo::classifyFiles(){
  return this->dataClassified;
}
