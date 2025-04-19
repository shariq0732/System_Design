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
    static int spNo;
    public: 

        ParkingFloor(int floorId, int smallPS, int compactPS, int largePS)
        {
            spNo++;

            for(int i = 0 ; i < smallPS; i++)
            {
                this->parkingSpotMap[SpotType::SMALL].push_back(new SmallParkingSpot(spNo, floorId, false, 10));
            }
            avialableParkingSpotMap[SpotType::SMALL] = smallPS;

            for(int i = 0 ; i < compactPS; i++)
            {
                this->parkingSpotMap[SpotType::COMPACT].push_back(new CompactParkingSpot(spNo, floorId, false, 20));
            }
            avialableParkingSpotMap[SpotType::COMPACT] = compactPS;

            for(int i = 0 ; i < largePS; i++)
            {
                this->parkingSpotMap[SpotType::LARGE].push_back(new LargeParkingSpot(spNo, floorId, false, 30));
            }
            avialableParkingSpotMap[SpotType::LARGE] = largePS;
        }

        SpotType getSpotTypeFromVehicleType(VechicleType vehicleType)
        {
            switch(vehicleType)
            {
                case VechicleType::BIKE :
                    return SpotType::SMALL;
                case VechicleType::CAR :
                    return SpotType::COMPACT;
                case VechicleType::TRUCK : 
                    return SpotType::LARGE;
            }
        }

        bool canPark(Vehicle* vehicle)
        {
            SpotType spotType = getSpotTypeFromVehicleType(vehicle->getVehicleType());
            
            if(avialableParkingSpotMap[spotType] > 0) return true;
            return false;
        }

        pair<pair<int,int>,int> parkVehicle(Vehicle* vehicle)
        {
            SpotType spotType = getSpotTypeFromVehicleType(vehicle->getVehicleType());

            for(auto& it : parkingSpotMap[spotType]) // this is pointer then return by value then
            {
                if(!it->getIsOccupied())
                {
                    it->parkVehicle(vehicle);
                    return {{it->getFloorId(), it->getSpotNo()}, it->getPrice()};
                }
            }
        }

        void vaccate(int spNo, Vehicle* vehicle)
        {  
            SpotType spotType = getSpotTypeFromVehicleType(vehicle->getVehicleType());
            for(auto& it : parkingSpotMap[spotType])
            {
                if(it->getSpotNo() == spNo)
                {
                    it->vaccate();
                }
            }
        }




};

int ParkingFloor::spNo = 0;

#endif