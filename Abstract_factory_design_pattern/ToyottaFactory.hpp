#ifndef TOYOTTA_FACTORY
#define TOYOTTA_FACTORY

#include "IvehicleFactory.hpp"
#include "ToyottaCar.hpp"
#include "ToyottaMotorCycle.hpp"

class ToyottaFactory: public IVehicleFactory 
{
    public :
        Icar* CreateCar();
        IMotorCycle* CreateMotorCycle();

        ~ToyottaFactory();
};

#endif