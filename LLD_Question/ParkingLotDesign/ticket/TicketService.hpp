#ifndef TICKETSERVICE_H
#define TICKETSERVICE_H

#include "Ticket.hpp"
#include <mutex>

class TicketService
{
    static TicketService* ticketService;
    static int ticketCounter;
    static mutex mt;
    
    TicketService() {}
    ~TicketService() {}
    public:

    TicketService(const TicketService&) = delete;
    TicketService& operator=(const TicketService&) = delete;
    TicketService(TicketService&&) = delete;
    TicketService& operator=(const TicketService&) = delete;


    static TicketService* getInstance()
    {
        if(nullptr  == ticketService)
        {
            mt.lock();
            if(nullptr == ticketService)
            {
                ticketService =  new TicketService();
            }
        }
        return ticketService;
    }

    void removeInstance()
    {
        delete this->ticketService;
    }

    Ticket* GenerateTicket(int floorNo, int spNo, int price, Vehicle *vehicle)
    {
        this->ticketCounter++;
        string ticketId = "TICKET " + to_string(this->ticketCounter);
        return new Ticket(ticketId, floorNo, spNo, price, vehicle);
    }
};

int TicketService::ticketCounter = 0;
mutex TicketService::mt;
#endif