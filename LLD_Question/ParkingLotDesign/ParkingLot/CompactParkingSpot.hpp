#include "ParkingSpot.hpp"

class CompactParkingSpot: public ParkingSpot
{
    public:

    CompactParkingSpot(int theSpotNo, int theFloorNo, bool theIsOccupied, int thePrice) : 
                        ParkingSpot(theSpotNo, theFloorNo, theIsOccupied, thePrice, SpotType::COMPACT) {}
                        
};