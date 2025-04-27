#ifndef TICKET_H
#define TICKET_H

#include "../ParkingLot/ParkingSpot.hpp"
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

class Ticket
{   
    string ticketId;
    int floorNo;
    int spNo;
    double price;
    double totalAmount;
    chrono::system_clock::time_point issueTime;
    string issueDate;
    string vaccateDate;
    Vehicle* vehicle;

    string getDateAndTime(chrono::system_clock::time_point& timePointInTime);

    public:

        Ticket(string theTicketId, int theFloorNo, int theSpNo, double thePrice, Vehicle* theVehicle);
        void setVaccateDate(chrono::system_clock::time_point vaccateTime);
        chrono::system_clock::time_point getIssueTime();
        int getFloorNo();
        int getSpotNo();
        int getPrice();
        void setTotalAmount(double totalAmount);
        int getTotalAmount();
        string getTicketId();
        Vehicle* getVehicle();
        string getIssueDate();
        string getVaccateDate();
        void print();
};

#endif