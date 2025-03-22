#ifndef HYUNDAI_FACTORY
#define HYUNDAI_FACTORY

#include "IvehicleFactory.hpp"
#include "HyundaiCar.hpp"
#include "HyundaiMotorCycle.hpp"

class HyundaiFactory: public IVehicleFactory
{
    public: 

        Icar* CreateCar();
        IMotorCycle* CreateMotorCycle();

        ~HyundaiFactory();
};  

#endif