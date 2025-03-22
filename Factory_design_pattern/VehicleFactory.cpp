#include "VehicleFactory.hpp"

Ivehicle* VehicleFactory::CreateVehicle(string vehicleType)
{
    Ivehicle *vehicle = nullptr;

    if("Car" == vehicleType)
    {
        vehicle = new Car();
    }
    else if("Motercycle" == vehicleType)
    {
        vehicle = new MoterCycle();
    }
    else if("Van" == vehicleType)
    {
        vehicle = new Van();
    }
    else
    {
        cout<<"Invalid vehicle type return nullptr" << endl;
    }

    return vehicle;
}