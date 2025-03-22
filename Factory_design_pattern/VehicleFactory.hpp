#ifndef VEHICLE_FACTORY

#include "Ivehicle.hpp"
#include "Van.hpp"
#include "Car.hpp"
#include "Motercycle.hpp"
#include <string>

class VehicleFactory
{
    
    public:
        static Ivehicle* CreateVehicle(string vehicleType);

};

#endif
