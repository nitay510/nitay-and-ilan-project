//
// Created by ilan talala on 18/01/2023.
//

#ifndef NITAY_AND_ILAN_LAST_MISSION_FUNC8_H
#define NITAY_AND_ILAN_LAST_MISSION_FUNC8_H

#include "Command.h"
class func8: public Command{
      string description="exit";
public:
    std::string getDesctiption() override;
      void execute() override;
};


#endif //NITAY_AND_ILAN_LAST_MISSION_FUNC8_H
