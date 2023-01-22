
#include <list>
#include "KNN.h"
#include "SocketIO.h"
class HoldInfo {
private:
    DefultIO* dio;
    std::list <std::vector<double>> testFile;
    KNN* knn;
    int k;
    Distance* dType;
    std::string dTypeName;
public:
    HoldInfo(DefultIO* dio);
    void setKnn(std::multimap<std::vector<double>,std::string> LabledPoints);
    void setDio(DefultIO* dio);
    void setTestFile(std::list <std::vector<double>> testFile);
    void setK(int k);
    void setdType(Distance* dType,std::string dTypeName);
    std::string predictWithK(std::vector<double> Point);
    int getK();
    std::string getDName();
    void write(std::string str);
    std::string read();
  };
