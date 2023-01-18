
#ifndef NITAY_AND_ILAN_SECOND_MILESTONE_DISTANCE_H
#define NITAY_AND_ILAN_SECOND_MILESTONE_DISTANCE_H
#include <vector>
#include "DistancesFunc.h"
//an interface (abstarct class) for all the distance function class
class Distance {
public:
    virtual double ComputeDistance(std::vector<double> v1,std::vector<double> v2) = 0;
    std::string description;
};


#endif //NITAY_AND_ILAN_SECOND_MILESTONE_DISTANCE_H
