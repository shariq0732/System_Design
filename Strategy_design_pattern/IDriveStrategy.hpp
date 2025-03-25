#ifndef DRIVE_STRATEGY
#define DRIVE_STRATEGY

#include <iostream>
#include <string>
using namespace std;

class IDriveStrategy
{
    public:
        virtual void Drive() = 0;

        virtual ~IDriveStrategy(){}
};

#endif