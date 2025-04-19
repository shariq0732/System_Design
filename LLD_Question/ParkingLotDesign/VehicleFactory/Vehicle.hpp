#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
#include "../Common/CommonEnum.hpp"

using namespace std;

class Vehicle
{
    string regNo;
    VechicleType vehicleTypes;

    public:
        Vehicle(string theRegNo, VechicleType theVehicleType): regNo(theRegNo), vehicleTypes(theVehicleType) {}

        VechicleType getVehicleType()
        {
            return this->vehicleTypes;
        }

        string getRegNo()
        {
            return this->regNo;
        }
};

#endif