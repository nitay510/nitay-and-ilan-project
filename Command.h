//
// Created by ilan talala on 18/01/2023.
//
#ifndef NITAY_AND_ILAN_LAST_MISSION_COMMAND_H
#define NITAY_AND_ILAN_LAST_MISSION_COMMAND_H
#include <string>
#include <iostream>
#include <vector>
#include <thread>
#include "HoldInfo.h"
using namespace std;
class Command {
public:
    virtual void execute()=0;
    virtual std::string getDesctiption()=0;
};


#endif //NITAY_AND_ILAN_LAST_MISSION_COMMAND_H
