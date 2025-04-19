#include "ParkingSpot.hpp"

class SmallParkingSpot: public ParkingSpot
{
    public:

        SmallParkingSpot(int theSpotNo, int theFloorNo, bool theIsOccupied, int thePrice) : 
                        ParkingSpot(theSpotNo, theFloorNo, theIsOccupied, thePrice, SpotType::SMALL) {}
                        
};