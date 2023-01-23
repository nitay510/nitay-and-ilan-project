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
    while (this->inf->read() == "clientReady") {
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
            std::cout << "the vector in the file wasnt good" << '\n';
            exit(1);
        }

        labledPoints.insert(std::pair<std::vector<double>, std::string>(v, name));
    }
     for(auto it=labledPoints.begin(); it!=labledPoints.end(); ++it) {
         std::cout<< "Vector: ";
         for(auto val: it->first)
             std::cout<< val<<" ";
         std::cout<<" Label: "<<it->second<<std::endl;
     }
    this->inf->setKnn(labledPoints);
    size = 0;

    std::list<std::vector<double>> test;
    this->inf->write("Please upload your local test CSV file.\n");
    std::cout<<"passed in server"<<std::endl;
    std::string isReady = this->inf->read();
    while (strcmp(isReady.c_str(),"testReady")==0) {
      std::cout << isReady << '\n';
        this->inf->write("Go");
        std::vector<double> v;
        std::string word;
        std::string line = this->inf->read();
        std::stringstream ss(line);
        double val;
        while (getline(ss, word, ',')) {
          if(checkIsDouble(word,val))
          v.push_back(val);
      }
            for (auto x : v) {
    std::cout << x << " ";
}
std::cout << std::endl;
        test.push_back(v);
        isReady = this->inf->read();
      }
    std::cout<<"finish"<<std::endl;
    this->inf->setTestFile(test);

    }
