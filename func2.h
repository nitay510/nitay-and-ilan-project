//
// Created by ilan talala on 18/01/2023.
//

#ifndef NITAY_AND_ILAN_LAST_MISSION_FUNC2_H
#define NITAY_AND_ILAN_LAST_MISSION_FUNC2_H

#include "Command.h"
class func2: public Command{
  std::string description="algorithm settings";
public:
  std::string getDesctiption();
    void execute();
};


#endif //NITAY_AND_ILAN_LAST_MISSION_FUNC3_H
