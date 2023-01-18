#include "DistancesFunc.h"
//function that check if string is double if it is put it in the double given by refernce
bool checkIsDouble(std::string inputString, double &result) {
    char* end;
    result = strtod(inputString.c_str(), &end);
    if (end == inputString.c_str() || *end != '\0') return false;
    return true;
}
//get to vectors and calculate sum of the absolute difference with pow of
//a given p
static double BasicCalVectors(vector<double> v1, vector<double> v2, int p) {
    double sum = 0;
    for (int i = 0; i < v1.size(); i++) {
        double temp = std::abs(v1[i] - v2[i]);
        temp = std::pow(temp, p);
        sum = sum + temp;
    }
    return sum;
}
//calculate manhattan distance using basicCalVectors with p=1
double ManhattanDistance(vector<double> v1, vector<double> v2) {
    return BasicCalVectors(v1, v2, 1);
}
//calculate euclidean distance using basicCalVectors with p=2 and do sqrt for all of this
double EuclideanDistance(vector<double> v1, vector<double> v2) {
    return std::sqrt(BasicCalVectors(v1, v2, 2));
}
//calculate minkowski distance using basicCalVectors with p as you like and do sqrt p for all of this
 double MinkowskiDistance(vector<double> v1, vector<double> v2, double p) {
    double sqrt = 1 / p;
    return std::pow(BasicCalVectors(v1, v2, p), sqrt);
}
//calculate Canberra distance,if there is 2 zeros, than dvide by zero will put Nan
 double CanberraDistance(vector<double> v1, vector<double> v2) {
    double distance = 0;
    for (int i = 0; i < v1.size(); i++) {
        distance += (fabs(v1[i] - v2[i])) / (fabs(v1[i]) + fabs(v2[i]));
    }
    return distance;
}
//calculate chebyshev distance,basckily look for the max distance between the values of the vector.
 double ChebyshevDistance(vector<double> v1, vector<double> v2) {
    double MaxDistance = 0;
    for (int i = 0; i < v1.size(); i++) {
        if (fabs(v1[i] - v2[i]) > MaxDistance) {
            MaxDistance = fabs(v1[i] - v2[i]);
        }
    }
    return MaxDistance;
}
