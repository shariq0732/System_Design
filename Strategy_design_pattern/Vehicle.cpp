#include "Vehicle.hpp"

Vehicle::Vehicle(){}

Vehicle::~Vehicle() {
    delete drive;
}

Vehicle::Vehicle(IDriveStrategy *aDrive)
{
    this->drive = aDrive;
}

void Vehicle::Drive()
{
    this->drive->Drive();
}