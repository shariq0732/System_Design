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
    int price;
    int totalAmount;
    chrono::system_clock::time_point issueTime;
    string issueDate;
    string vaccateDate;
    Vehicle* vehicle;

    string getDateAndTime(chrono::system_clock::time_point& timePointInTime)
    {
        std::time_t timeInSecondSinceEpoch = chrono::system_clock::to_time_t(timePointInTime);
        std::tm* clenderTimePtr = localtime(&timeInSecondSinceEpoch);
        
        ostringstream oss;
        oss <<  put_time(clenderTimePtr, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }

    public:

        Ticket(string theTicketId, int theFloorNo, int theSpNo, int thePrice, Vehicle* theVehicle): ticketId(theTicketId), floorNo(theFloorNo), spNo(theSpNo), price(thePrice),  vehicle(theVehicle)
        {
            this->issueTime = chrono::system_clock::now();
            this->issueDate = getDateAndTime(this->issueTime);
        }


        void setVaccateDate(chrono::system_clock::time_point vaccateTime)
        {
            this->vaccateDate = getDateAndTime(vaccateTime);
        }

        chrono::system_clock::time_point getIssueTime()
        {
            return this->issueTime;
        }

        int getFloorNo()
        {
            return this->floorNo;
        }

        int getSpotNo()
        {
            return this->spNo;
        }
        
        int getPrice()
        {
            return this->price;
        }

        void setTotalAmount(int totalAmount)
        {
            this->totalAmount = totalAmount;
        }
        int getTotalAmount()
        {
            return this->totalAmount;
        }

        string getTicketId()
        {
            return this->ticketId;
        }

        Vehicle* getVehicle()
        {
            return this->vehicle;
        }

        string getIssueDate()
        {
            return this->issueDate;
        }

        string getVaccateDate()
        {
            return this->vaccateDate;
        }
};

#endif