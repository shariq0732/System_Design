#ifndef VEHICLE
#define VEHICLE

#include <iostream>
#include <string>
#include "IDriveStrategy.hpp"
using namespace std;

class Vehicle
{
    IDriveStrategy *drive;
    public:

        Vehicle();
        Vehicle(IDriveStrategy *aDrive);

        virtual void Drive();

        virtual ~Vehicle();     
};

#endif