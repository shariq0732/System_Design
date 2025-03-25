#include "Vehicle.hpp"

class OffRoadVehicle: public Vehicle
{
    public:
        OffRoadVehicle()
        {

        }

        OffRoadVehicle(IDriveStrategy *drive) : Vehicle(drive)
        {

        }

        ~OffRoadVehicle() {}
};