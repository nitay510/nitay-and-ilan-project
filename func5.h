//
// Created by ilan talala on 18/01/2023.
//

#ifndef NITAY_AND_ILAN_LAST_MISSION_FUNC5_H
#define NITAY_AND_ILAN_LAST_MISSION_FUNC5_H

#include "Command.h"
class func5: public Command{
    HoldInfo* inf;
    string description="download results";
public:
    func5(HoldInfo* inf);
    std::string getDesctiption() override;
    void execute() override;
    void download(string localPath,string mapS);
};


#endif //NITAY_AND_ILAN_LAST_MISSION_FUNC5_H
