#ifndef ENTRANCEPANEL_H
#define ENTRANCEPANEL_H


#include <iostream>
#include "Gate.hpp"
#include "../ParkingLot/ParkingLot.cpp"
#include "../VehicleFactory/Vehicle.hpp"
#include "../ticket/TicketService.hpp"
using namespace std;

class EntrancePanel:public Gate
{
    ParkingLot *parkingLot;
    TicketService *ticketService;

    public:
    
        EntrancePanel(int gateId): Gate(gateId) {
            parkingLot = ParkingLot::getInstance();
        }


        bool canPark(Vehicle* vehicle)
        {
            return this->parkingLot->canPark(vehicle);
        }

        
        Ticket* ParkVehicleAndGenerateTicke(Vehicle* vehicle)
        {
            pair<pair<int,int>,int> floorAndSpotNo = this->parkingLot->parkVehicle(vehicle);
            return ticketService->GenerateTicket(floorAndSpotNo.first.first, floorAndSpotNo.first.second, floorAndSpotNo.second, vehicle);
        }

};

#endif