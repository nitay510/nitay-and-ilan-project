
#ifndef NITAY_AND_ILAN_SECOND_MILESTONE_MANDISTANCE_H
#define NITAY_AND_ILAN_SECOND_MILESTONE_MANDISTANCE_H

#include "Distance.h"
//a class for Mankovski distance
class ManDistance : public Distance{
public:
    double ComputeDistance(std::vector<double> v1, std::vector<double> v2) override;
    std::string description="MAN";
};


#endif //NITAY_AND_ILAN_SECOND_MILESTONE_MANDISTANCE_H
