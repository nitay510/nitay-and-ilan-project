#ifndef NITAY_AND_ILAN_SECOND_MILESTONE_KNN_H
#define NITAY_AND_ILAN_SECOND_MILESTONE_KNN_H
#include <map>
#include<vector>
#include<string>
#include "Distance.h"
#include "EucDistance.h"
#include "CheDistance.h"
#include "ManDistance.h"
#include "MinDistance.h"
#include "CanDistance.h"
//a class that get a k and multimap and now how to predict acording to the k and some distance function
class KNN {
    std::multimap<std::vector<double>,std::string> LabledPoints;
public:
    KNN(std::multimap<std::vector<double>,std::string> LabledPoints);
    std:: string predict(std::vector<double> Point,Distance* dType, int k);
};


#endif //NITAY_AND_ILAN_SECOND_MILESTONE_KNN_H
