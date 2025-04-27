#ifndef PARKING_FLOOR_H
#define PARKING_FLOOR_H

#include "SmallParkingSpot.hpp"
#include "CompactParkingSpot.hpp"
#include "LargeParkingSpot.hpp"
#include <unordered_map>
#include <vector>
using namespace std;


class ParkingFloor
{

    unordered_map<SpotType, vector<ParkingSpot*>> parkingSpotMap;
    unordered_map<SpotType, int> avialableParkingSpotMap;
    int spNo;
    public: 

        ParkingFloor();
        ParkingFloor(int floorId, int smallPS, int compactPS, int largePS);
        SpotType getSpotTypeFromVehicleType(VechicleType vehicleType);
        bool canPark(Vehicle* vehicle);
        pair<pair<int,int>,int> parkVehicle(Vehicle* vehicle);
        void vaccate(int spNo, Vehicle* vehicle);

};


#endif