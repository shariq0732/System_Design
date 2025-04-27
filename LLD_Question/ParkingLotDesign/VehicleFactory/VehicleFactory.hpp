#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H

#include "Bike.hpp"
#include "Car.hpp"
#include "Truck.hpp"

class VehicleFactory
{
    public:
        VehicleFactory();
        static Vehicle* getVehicle(string name, string regNo);
};


#endif