#ifndef ENTRANCEPANEL_H
#define ENTRANCEPANEL_H


#include <iostream>
#include "Gate.hpp"
#include "../ticket/TicketService.hpp"
#include "../VehicleFactory/VehicleFactory.hpp"
using namespace std;

class ParkingLot;

class EntrancePanel:public Gate
{
    ParkingLot *parkingLot;
    TicketService *ticketService;

    Ticket* ParkVehicleAndGenerateTicke(Vehicle* vehicle);
    public:
        EntrancePanel(int gateId);
        Ticket* ProcessEntrance();
};

#endif