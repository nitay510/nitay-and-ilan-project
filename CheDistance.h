
#ifndef NITAY_AND_ILAN_SECOND_MILESTONE_CHEDISATANCE_H
#define NITAY_AND_ILAN_SECOND_MILESTONE_CHEDISATANCE_H

#include "Distance.h"
//a class for chebishav distance
class CheDistance : public Distance{
public:
    virtual double ComputeDistance(std::vector<double> v1, std::vector<double> v2) override;
};



#endif //NITAY_AND_ILAN_SECOND_MILESTONE_CHEDISATANCE_H
