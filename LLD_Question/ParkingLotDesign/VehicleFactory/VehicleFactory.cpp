#include "Bike.hpp"
#include "Car.hpp"
#include "Truck.hpp"

class VehicleFactory
{

    public:

        static Vehicle* getVehicle(string vehicleName, string regNo)
        {
            if("Bike" == vehicleName)
                return new Bike(regNo);
            else if("Car" == vehicleName)
                return new Car(regNo);
            else
                return new Truck(regNo);
        }
};