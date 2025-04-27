#include "Ticket.hpp"


Ticket::Ticket(string theTicketId, int theFloorNo, int theSpNo, double thePrice, Vehicle* theVehicle): ticketId(theTicketId), floorNo(theFloorNo), spNo(theSpNo), price(thePrice),  vehicle(theVehicle)
{
    this->issueTime = chrono::system_clock::now();
    this->issueDate = getDateAndTime(this->issueTime);
}

string Ticket::getDateAndTime(chrono::system_clock::time_point& timePointInTime)
{
    std::time_t timeInSecondSinceEpoch = chrono::system_clock::to_time_t(timePointInTime);
    std::tm* clenderTimePtr = localtime(&timeInSecondSinceEpoch);
    
    ostringstream oss;
    oss <<  put_time(clenderTimePtr, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}


void Ticket::setVaccateDate(chrono::system_clock::time_point vaccateTime)
{
    this->vaccateDate = getDateAndTime(vaccateTime);
}

chrono::system_clock::time_point Ticket::getIssueTime()
{
    return this->issueTime;
}

int Ticket::getFloorNo()
{
    return this->floorNo;
}

int Ticket::getSpotNo()
{
    return this->spNo;
}

int Ticket::getPrice()
{
    return this->price;
}

void Ticket::setTotalAmount(double totalAmount)
{
    this->totalAmount = totalAmount;
}
int Ticket::getTotalAmount()
{
    return this->totalAmount;
}

string Ticket::getTicketId()
{
    return this->ticketId;
}

Vehicle* Ticket::getVehicle()
{
    return this->vehicle;
}

string Ticket::getIssueDate()
{
    return this->issueDate;
}

string Ticket::getVaccateDate()
{
    return this->vaccateDate;
}

void Ticket::print()
{
    cout<<"********* Ticket Details *********" << endl;
    cout<<ticketId <<endl;
    cout<<issueDate <<endl;
    cout<<vaccateDate <<endl;
    cout<<totalAmount <<endl;
}