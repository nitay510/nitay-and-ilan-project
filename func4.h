//
// Created by ilan talala on 18/01/2023.
//

#ifndef NITAY_AND_ILAN_LAST_MISSION_FUNC4_H
#define NITAY_AND_ILAN_LAST_MISSION_FUNC4_H

#include "Command.h"
class func4: public Command{
    HoldInfo* inf;
    string description="display results";
public:
  func4(HoldInfo* inf);
    std::string getDesctiption() override;
      void execute() override;
};


#endif //NITAY_AND_ILAN_LAST_MISSION_FUNC4_H
