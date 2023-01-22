//
// Created by ilan talala on 18/01/2023.
//
#include "func1.h"
#include "func2.h"
#include "func3.h"
#include "func4.h"
#include "func5.h"
#include "Command.h"
#ifndef NITAY_AND_ILAN_LAST_MISSION_CLI_H
#define NITAY_AND_ILAN_LAST_MISSION_CLI_H
class CLI {
private:
    DefultIO* DIO;
    HoldInfo* info;
    map<int,Command*> functions;
public:
    void start();
    int menu();
    CLI(DefultIO* IO);
    ~CLI();
};



#endif //NITAY_AND_ILAN_LAST_MISSION_CLI_H
