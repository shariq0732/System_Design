#include "Vehicle.hpp"

class PassengerVehicle: public Vehicle
{
    public:

        PassengerVehicle() {}

        PassengerVehicle(IDriveStrategy *drive) : Vehicle(drive) {}

        ~PassengerVehicle() {}
};
