#include "VehicleFactory.hpp"

VehicleFactory::VehicleFactory() {}

Vehicle* VehicleFactory::getVehicle(string vehicleName, string regNo)
{
    if("Bike" == vehicleName)
        return new Bike(regNo);
    else if("Car" == vehicleName)
        return new Car(regNo);
    else
        return new Truck(regNo);
}
