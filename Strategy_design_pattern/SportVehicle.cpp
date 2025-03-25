#include "Vehicle.hpp"

class SportVehicle: public Vehicle
{  

    public:

        SportVehicle(){}

        SportVehicle(IDriveStrategy *drive): Vehicle(drive) {}

        ~SportVehicle() {}

};