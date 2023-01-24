#include "func1.h"
#include <vector>
#include <sstream>
#include <list>

func1::func1(HoldInfo* inf){
  this->inf = inf;
}
std::string func1::getDesctiption(){
  return this->description;
}
void func1::execute() {
    int size = 0;
    std::multimap<std::vector<double>, std::string> labledPoints;
    this->inf->write("Please upload your local train CSV file.\n");
    bool checkInvalid1 = true;
    while (this->inf->read() == "clientReady") {
      checkInvalid1=false;
        this->inf->write("Go");
        std::vector<double> v;
        std::string word;
        std::stringstream is(this->inf->read());
        double val;
        std::string name;
        bool check = true;
        //read the  numbers and the name
        while (check) {
            getline(is, word, ',');
            check = checkIsDouble(word, val);
            if (check)
                v.push_back(val);
            else
                name = word;
        }
        //to get the size of first vector
        if (size == 0) {
            size = v.size();
        }
        //check if it was a valid vector if it does put it in the map
        if (is.rdbuf()->in_avail() != 0 || v.size() != size) {
          this->inf->write("!Finish");
          return;
        }
        labledPoints.insert(std::pair<std::vector<double>, std::string>(v, name));
    }
    if(!checkInvalid1) {
    this->inf->setKnn(labledPoints);
    std::list<std::vector<double>> test;
    this->inf->write("Please upload your local test CSV file.\n");
    bool checkInvalid = false;
    std::string isReady = this->inf->read();
    if(strcmp(isReady.c_str(),"testReady")!=0)
    checkInvalid=true;
    while (strcmp(isReady.c_str(),"testReady")==0) {
        this->inf->write("Go");
        std::vector<double> v1;
        std::string word;
        std::string line = this->inf->read();
        std::stringstream ss(line);
        double val;
        while (getline(ss, word, ',')) {
          if(checkIsDouble(word,val))
          v1.push_back(val);
      }
      ss>>val;
      if(val!=v1.back())
      v1.push_back(val);
      if(v1.size()!=size){
        this->inf->write("Finish");
        return;
      }
        test.push_back(v1);
        isReady = this->inf->read();
      }
    if(!checkInvalid)
    this->inf->setTestFile(test);
    }
  }
