
#ifndef NITAY_ILAN_PROJECT_EX1_H
#define NITAY_ILAN_PROJECT_EX1_H
#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::cout;
using std::cin;
 bool checkIsDouble(std::string inputString, double &result);
static double BasicCalVectors(vector<double> v1,vector<double> v2,int p);
double ManhattanDistance(vector<double> v1,vector<double> v2);
double  EuclideanDistance(vector<double> v1,vector<double> v2);
double  MinkowskiDistance(vector<double> v1,vector<double> v2,double p);
double CanberraDistance(vector<double> v1, vector<double> v2);
double ChebyshevDistance(vector<double> v1, vector<double> v2);
#endif //NITAY_ILAN_PROJECT_EX1_H
