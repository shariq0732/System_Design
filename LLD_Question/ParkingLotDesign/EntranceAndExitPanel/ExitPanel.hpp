#ifndef EXITPANEL_H
#define EXITPANEL_H

#include <iostream>
#include "Gate.hpp"
#include "../ticket/TicketService.hpp"
#include "../PaymentService/PaymentFactory.cpp"
#include <cmath>
using namespace std;

class ParkingLot;

class ExitPanel: public Gate
{  
   
    ParkingLot *parkingLot;
    TicketService *ticketService;

    int calculateTotalAmount(chrono::system_clock::time_point parkTime, chrono::system_clock::time_point exitTime);
    void ProcessPayment(double totalAmount);
    void exitVehicleAndTakePayment(Ticket* ticket);
    public:
        ExitPanel(int gateId);

        void ProcessExit(Ticket *ticket);
};

#endif