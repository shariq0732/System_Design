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
        ParkingSpot();
        ParkingSpot(int theSpotNo, int theFloorNo, bool theIsOccupied, int thePrice, SpotType theSpotType, Vehicle *theVehicle = nullptr);
        ParkingSpot(const ParkingSpot& theParkingSpot);
        void parkVehicle(Vehicle* vehicle);
        int getSpotNo();
        int getFloorId();
        void setPrice(int thePrice);
        bool getIsOccupied();
        void vaccate();
        int getPrice();
};

#endif