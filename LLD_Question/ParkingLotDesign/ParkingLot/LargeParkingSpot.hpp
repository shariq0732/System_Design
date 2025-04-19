#include "ParkingSpot.hpp"

class LargeParkingSpot: public ParkingSpot
{
    public:

    LargeParkingSpot(int theSpotNo, int theFloorNo, bool theIsOccupied, int thePrice) : 
                        ParkingSpot(theSpotNo, theFloorNo, theIsOccupied, thePrice, SpotType::LARGE) {}
                        
};