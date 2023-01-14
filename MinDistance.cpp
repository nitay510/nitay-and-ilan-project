
#include "MinDistance.h"

double MinDistance::ComputeDistance(std::vector<double> v1, std::vector<double> v2) {
    return MinkowskiDistance(v1, v2,2);

}

