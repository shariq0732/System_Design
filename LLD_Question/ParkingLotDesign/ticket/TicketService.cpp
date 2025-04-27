#include "TicketService.hpp"

int TicketService::ticketCounter = 0;
mutex TicketService::mt;
TicketService* TicketService::ticketService = nullptr;

TicketService::TicketService() {}
TicketService::~TicketService() {}

TicketService* TicketService::getInstance()
{
    if(nullptr  == ticketService)
    {
        mt.lock();
        if(nullptr == ticketService)
        {
            ticketService =  new TicketService();
        }
        mt.unlock();
    }
    return ticketService;
}

void TicketService:: removeInstance()
{
    delete this->ticketService;
}

Ticket* TicketService::GenerateTicket(int floorNo, int spNo, int price, Vehicle *vehicle)
{
    this->ticketCounter++;
    string ticketId = "TICKET " + to_string(this->ticketCounter);
    return new Ticket(ticketId, floorNo, spNo, price, vehicle);
}

void TicketService::addTicket(Ticket ticket)
{
    this->ticketHistory.push_back(ticket);
}

Ticket* TicketService::getTicketById(string ticketId)
{ 
    for(auto& it : this->ticketHistory)
    {
        if(ticketId == it.getTicketId())
            return &it;
    }
    return nullptr;
}

void TicketService::viewTicketHistory()
{
    cout<<"********************Ticket History********************" << endl;
    for(auto it : ticketHistory)
    {
        cout<<"****************************************" <<endl;
        cout<<it.getTicketId() << endl;
        cout<<it.getVehicle()->getRegNo() << endl;
        cout<<it.getVehicle()->getVehicleType() << endl;
        cout<< it.getIssueDate() <<  endl;
        cout<<it.getVaccateDate() << endl;
        cout<<it.getTotalAmount() << endl;
    }
}