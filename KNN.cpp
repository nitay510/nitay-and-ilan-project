
#include <iostream>
#include "KNN.h"
//Constructor to the KNN class
KNN::KNN(std::multimap<std::vector<double>, std::string> LabledPoints) {
    this->LabledPoints=LabledPoints;
}
//This function get a vector and Distance type pointer and calculate the k closest neighbors to that vector
std::string KNN::predict(std::vector<double> Point,Distance* dType,int k) {
    std::multimap<double,std::string> distances;
    //calculate the distances from the vector and put it in a nultimap of distance per type.
    for(auto it=this->LabledPoints.begin(); it != this->LabledPoints.end(); it++){
      if(it->first.size()!=Point.size()){
        std::string uneaven = "invalid input";
        return uneaven;
      }
        distances.insert(std::pair<double,std::string>(dType->ComputeDistance(Point, it->first), it->second));
    }//the map is sorted by the key automatically
    std::map<std::string,int> counter; //this map count the number of instances of each type.
    int i = 1;
    int max = 0;//to keep the count of most common type
    std::string type;//the type
    //Passing on multimap "distance" to count for the K smallest values which are the most filtered type
    for(auto it=distances.begin(); it != distances.end(); it++){
        counter[it->second]++;
        if(counter[it->second] > max){
            max = counter[it->second];
            type = it->second;
        }
        if(i==k)
            break;
        i++;
    }
    return type;
}
