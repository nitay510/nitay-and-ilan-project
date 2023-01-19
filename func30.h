//
// Created by ilan talala on 18/01/2023.
//

#ifndef NITAY_AND_ILAN_LAST_MISSION_FUNC3_H
#define NITAY_AND_ILAN_LAST_MISSION_FUNC3_H

#include "Command.h"
class func3: public Command{
      string description="classify data";
public:
    std::string getDesctiption() override;
      void execute() override;
};


#endif //NITAY_AND_ILAN_LAST_MISSION_FUNC3_H
