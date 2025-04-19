#include "Vehicle.hpp"

class Truck: public Vehicle
{
    public:
        Truck(string theRegNo): Vehicle(theRegNo, VechicleType::TRUCK) {}
};