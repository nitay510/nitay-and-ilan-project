//
// Created by ilan talala on 18/01/2023.
//

#ifndef NITAY_AND_ILAN_LAST_MISSION_FUNC1_H
#define NITAY_AND_ILAN_LAST_MISSION_FUNC1_H

#include "Command.h"
class func1: public Command{
public:
    string description="upload an unclassified csv data file";
    void execute();
};


#endif //NITAY_AND_ILAN_LAST_MISSION_FUNC1_H
