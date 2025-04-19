#include "Vehicle.hpp"

class Car: public Vehicle
{
    public:
        Car(string theRegNo): Vehicle(theRegNo, VechicleType::CAR) {}
};