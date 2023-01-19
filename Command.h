//
// Created by ilan talala on 18/01/2023.
//

#ifndef NITAY_AND_ILAN_LAST_MISSION_COMMAND_H
#define NITAY_AND_ILAN_LAST_MISSION_COMMAND_H
#include <string>
#include <iostream>
#include <vector>
#include "SocketIO.h"
using namespace std;
class Command {
public:
    virtual void execute()=0;
    std::string description;
protected:
    DefultIO* dio;
};


#endif //NITAY_AND_ILAN_LAST_MISSION_COMMAND_H
