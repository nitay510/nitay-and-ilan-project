//
// Created by ilan talala on 18/01/2023.
//

#ifndef NITAY_AND_ILAN_LAST_MISSION_FUNC3_H
#define NITAY_AND_ILAN_LAST_MISSION_FUNC3_H

#include "Command.h"
class func3: public Command{
      HoldInfo* inf;
      string description="classify data";
public:
    func3(HoldInfo* inf);
    std::string getDesctiption() override;
      void execute() override;
};


#endif //NITAY_AND_ILAN_LAST_MISSION_FUNC3_H
