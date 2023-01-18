
#include "CheDistance.h"
double CheDistance::ComputeDistance(std::vector<double> v1, std::vector<double> v2) {
    return ChebyshevDistance(v1, v2);
}
