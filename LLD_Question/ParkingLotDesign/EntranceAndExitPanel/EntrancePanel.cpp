
#include "EntrancePanel.hpp"
#include "../ParkingLot/ParkingLot.hpp"

EntrancePanel::EntrancePanel(int gateId): Gate(gateId) {
    parkingLot = ParkingLot::getInstance();
    ticketService = TicketService::getInstance();
}



Ticket* EntrancePanel::ParkVehicleAndGenerateTicke(Vehicle* vehicle)
{
    pair<pair<int,int>,int> floorAndSpotNo = this->parkingLot->parkVehicle(vehicle);
    if(floorAndSpotNo.first.first == -1 && floorAndSpotNo.first.second == -1)
    {
        return nullptr;
    }
    Ticket* ticket = ticketService->GenerateTicket(floorAndSpotNo.first.first, floorAndSpotNo.first.second, floorAndSpotNo.second, vehicle);
    this->ticketService->addTicket(*ticket);
    return ticket;
}

Ticket* EntrancePanel::ProcessEntrance()
{
    Ticket* ticket = nullptr;
    string name;
    string regNo;
    cout<< "Enter the vechile name and it's registration number" << endl;
    cin>> name;
    cin>> regNo;

    Vehicle* vehicle = VehicleFactory::getVehicle(name, regNo);
    ticket = ParkVehicleAndGenerateTicke(vehicle);
    return ticket;
}