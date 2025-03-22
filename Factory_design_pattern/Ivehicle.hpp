#ifndef VEHICLE
#define VEHICLE

#include <iostream>
using namespace std;

class Ivehicle
{
    public:
        virtual void CreateVehicle() = 0;

        virtual ~Ivehicle()
        {

        }
};

#endif