#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
class DefultIO {
public:
    virtual std::string read () = 0;
    virtual void write(std::string s1) = 0;
};
