//
// Created by ilan talala on 18/01/2023.
//

#ifndef NITAY_AND_ILAN_LAST_MISSION_CLI_H
#define NITAY_AND_ILAN_LAST_MISSION_CLI_H
#include "Command.h"
#include "KNN.h"
class CLI {
private:
    DefultIO* DIO;
    KNN* knn;
    Distance* metrica;
    int K;
    map<int,Command*> functions;
    int menu();
public:
    void start();
    CLI(DefultIO* IO);
    ~CLI();
};



#endif //NITAY_AND_ILAN_LAST_MISSION_CLI_H
