#include "Vehicle.hpp"

class Bike: public Vehicle
{
    public:
        Bike(string regNo) : Vehicle(regNo, VechicleType::BIKE) {}
};