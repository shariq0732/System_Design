#include "ToyottaFactory.hpp"

ToyottaFactory::~ToyottaFactory() {}

Icar* ToyottaFactory::CreateCar()
{
    return new ToyottaCar();
}

IMotorCycle* ToyottaFactory::CreateMotorCycle()
{
    return new ToyottaMotorCycle();
}