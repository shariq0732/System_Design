#include "AbstractFactory.hpp"
#include "HyundaiCar.hpp"
#include "HyundaiMotorCycle.hpp"
#include "ToyottaCar.hpp"
#include "ToyottaMotorCycle.hpp"

using namespace std;

int main()
{
    IVehicleFactory* vehicleFactory = nullptr;
    vehicleFactory = AbstractFactory::CreateFactory("Toyotta");
    Icar* car = vehicleFactory->CreateCar();
    IMotorCycle* motorCycle = vehicleFactory->CreateMotorCycle();

    car->CreateCar();
    motorCycle->CreateMotorCycle();

    delete car;
    delete motorCycle;

    return 0;
}