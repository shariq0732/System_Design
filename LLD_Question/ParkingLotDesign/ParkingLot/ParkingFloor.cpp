#include "ParkingFloor.hpp"

ParkingFloor::ParkingFloor() {}

ParkingFloor::ParkingFloor(int floorId, int smallPS, int compactPS, int largePS)
{
    cout<<"ParkingFloor::ctor " <<endl;
    spNo = 0;
    for(int i = 0 ; i < smallPS; i++)
    {
        spNo++;
        this->parkingSpotMap[SpotType::SMALL].push_back(new SmallParkingSpot(spNo, floorId, false, 10));
    }
    avialableParkingSpotMap[SpotType::SMALL] = smallPS;
    
    for(int i = 0 ; i < compactPS; i++)
    {
        spNo++;
        this->parkingSpotMap[SpotType::COMPACT].push_back(new CompactParkingSpot(spNo, floorId, false, 20));
    }
    avialableParkingSpotMap[SpotType::COMPACT] = compactPS;

    for(int i = 0 ; i < largePS; i++)
    {
        spNo++;
        this->parkingSpotMap[SpotType::LARGE].push_back(new LargeParkingSpot(spNo, floorId, false, 30));
    }
    avialableParkingSpotMap[SpotType::LARGE] = largePS;
}

SpotType ParkingFloor::getSpotTypeFromVehicleType(VechicleType vehicleType)
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
    return SpotType::COMPACT;
}

bool ParkingFloor::canPark(Vehicle* vehicle)
{
    SpotType spotType = getSpotTypeFromVehicleType(vehicle->getVehicleType());
    
    if(avialableParkingSpotMap[spotType] > 0)
    {
        return true;
    }
    return false;
}

pair<pair<int,int>,int> ParkingFloor::parkVehicle(Vehicle* vehicle)
{
    SpotType spotType = getSpotTypeFromVehicleType(vehicle->getVehicleType());

    for(auto& it : parkingSpotMap[spotType]) // this is pointer then return by value then
    {
        if(!it->getIsOccupied())
        {
            it->parkVehicle(vehicle);
            this->avialableParkingSpotMap[spotType]--;
            return {{it->getFloorId(), it->getSpotNo()}, it->getPrice()};
        }
    }
    return {{-1,-1},-1};
}

void ParkingFloor::vaccate(int spNo, Vehicle* vehicle)
{  
    SpotType spotType = getSpotTypeFromVehicleType(vehicle->getVehicleType());
    for(auto& it : parkingSpotMap[spotType])
    {
        if(it->getSpotNo() == spNo)
        {
            it->vaccate();
            this->avialableParkingSpotMap[spotType]++;
        }
    }
}
