#ifndef VEHICLE_FACTORY
#define VEHICLE_FACTORY

#include <iostream>
#include "Icar.hpp"
#include "ImotorCycle.hpp"
using namespace std;

class IVehicleFactory
{
    public:

        virtual Icar* CreateCar() = 0;
        virtual IMotorCycle* CreateMotorCycle() = 0;

        virtual ~IVehicleFactory() {}
};

#endif