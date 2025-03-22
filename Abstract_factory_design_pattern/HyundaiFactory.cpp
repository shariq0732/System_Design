#include "HyundaiFactory.hpp"

HyundaiFactory::~HyundaiFactory() {}

Icar* HyundaiFactory::CreateCar()
{
    return new HyundaiCar();
}

IMotorCycle* HyundaiFactory::CreateMotorCycle()
{
    return new HyundaiMotorCycle();
}