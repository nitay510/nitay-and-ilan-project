//
// Created by ilan talala on 18/01/2023.
//

#ifndef NITAY_AND_ILAN_LAST_MISSION_FUNC1_H
#define NITAY_AND_ILAN_LAST_MISSION_FUNC1_H

#include "Command.h"
class func1: public Command{
      HoldInfo* inf;
      string description="upload an unclassified csv data file";
public:
  func1(HoldInfo* inf);
  std::string getDesctiption() override;
    void execute() override;
};


#endif //NITAY_AND_ILAN_LAST_MISSION_FUNC1_H
