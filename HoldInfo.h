
#include <list>
#include "KNN.h"
#include "SocketIO.h"
class HoldInfo {
private:
    DefultIO* dio;
    std::map<int,std::string> filesAfterPredict;
    std::list <std::vector<double>> testFile;
    KNN* knn;
    int k;
    Distance* dType;
    std::string dTypeName;
    bool haveTestFile;
    bool haveFile;
public:
    HoldInfo(DefultIO* dio);
    void setPredict(std::map<int,std::string> filesAfterPredict);
    void setKnn(std::multimap<std::vector<double>,std::string> LabledPoints);
    void setDio(DefultIO* dio);
    void setTestFile(std::list <std::vector<double>> testFile);
    void setK(int k);
    void setdType(Distance* dType,std::string dTypeName);
    std::string predictWithK(std::vector<double> Point);
    int getK();
    bool haveFiles();
    std::string getDName();
    std::list <std::vector<double>>getTestFile();
    std::map<int,std::string> getPredictList();
    void write(std::string str);
    std::string read();
  };
