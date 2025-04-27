#include "ParkingSpot.hpp"

ParkingSpot::ParkingSpot() {}
ParkingSpot::ParkingSpot(int theSpotNo, int theFloorNo, bool theIsOccupied, int thePrice, SpotType theSpotType, Vehicle *theVehicle) :
            spotNo(theSpotNo), floorNo(theFloorNo), isOccupied(theIsOccupied), price(thePrice), spotType(theSpotType), vehicle(theVehicle) { }

ParkingSpot::ParkingSpot(const ParkingSpot& theParkingSpot)
{
    this->floorNo = theParkingSpot.floorNo;
    this->spotNo = theParkingSpot.spotNo;
    this->isOccupied = theParkingSpot.isOccupied;
    this->vehicle = theParkingSpot.vehicle;
    this->price = theParkingSpot.price;
    this->spotType = theParkingSpot.spotType;
}

void ParkingSpot::parkVehicle(Vehicle* vehicle)
{
    this->vehicle = vehicle;
    this->isOccupied = true;
}

int ParkingSpot::getSpotNo(){
    return this->spotNo;
}

int ParkingSpot::getFloorId()
{
    return this->floorNo;
}

void ParkingSpot::setPrice(int thePrice)
{
    this->price = thePrice;
}

bool ParkingSpot::getIsOccupied()
{
    return this->isOccupied;
}

void ParkingSpot::vaccate()
{
    this->isOccupied = false;
    delete this->vehicle;
}

int ParkingSpot::getPrice()
{
    return this->price;
}