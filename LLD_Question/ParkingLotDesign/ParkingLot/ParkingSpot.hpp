#ifndef PARKING_SPOT_H
#define PARKING_SPOT_H

#include <iostream>
#include <string>
#include "../VehicleFactory/Vehicle.hpp"
using namespace std;

class ParkingSpot
{
    int spotNo;
    int floorNo;
    bool isOccupied;
    Vehicle *vehicle;
    int price;
    SpotType spotType;

    public:
        ParkingSpot() {}
        ParkingSpot(int theSpotNo, int theFloorNo, bool theIsOccupied, int thePrice, SpotType theSpotType, Vehicle *theVehicle = nullptr) :
                    spotNo(theSpotNo), floorNo(theFloorNo), isOccupied(theIsOccupied), price(thePrice), spotType(theSpotType), vehicle(theVehicle) { }
        
        ParkingSpot(const ParkingSpot& theParkingSpot)
        {
            this->floorNo = theParkingSpot.floorNo;
            this->spotNo = theParkingSpot.spotNo;
            this->isOccupied = theParkingSpot.isOccupied;
            this->vehicle = theParkingSpot.vehicle;
            this->price = theParkingSpot.price;
            this->spotType = theParkingSpot.spotType;
        }

        void parkVehicle(Vehicle* vehicle)
        {
            this->vehicle = vehicle;
            this->isOccupied = true;
        }

        int getSpotNo(){
            return this->spotNo;
        }
        
        int getFloorId()
        {
            return this->floorNo;
        }

        void setPrice(int thePrice)
        {
            this->price = thePrice;
        }

        bool getIsOccupied()
        {
            return this->isOccupied;
        }

        void vaccate()
        {
            this->isOccupied = false;
            delete this->vehicle;
        }

        int getPrice()
        {
            return this->price;
        }
};

#endif