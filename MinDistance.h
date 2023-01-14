

#ifndef NITAY_AND_ILAN_SECOND_MILESTONE_MINDISTANCE_H
#define NITAY_AND_ILAN_SECOND_MILESTONE_MINDISTANCE_H

#include "Distance.h"
class MinDistance : public Distance{
public:
    virtual double ComputeDistance(std::vector<double> v1, std::vector<double> v2) override;
};


#endif //NITAY_AND_ILAN_SECOND_MILESTONE_MINDISTANCE_H
