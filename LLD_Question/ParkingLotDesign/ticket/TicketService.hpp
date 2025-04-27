#ifndef TICKETSERVICE_H
#define TICKETSERVICE_H

#include "Ticket.hpp"
#include <vector>
#include <mutex>

class TicketService
{
    static TicketService* ticketService;
    static int ticketCounter;
    static mutex mt;
    vector<Ticket> ticketHistory;
    TicketService();
    ~TicketService();
    TicketService(const TicketService&) = delete;
    TicketService& operator=(const TicketService&) = delete;
    TicketService(TicketService&&) = delete;
    TicketService& operator=(TicketService&&) = delete;
    public:


    static TicketService* getInstance();
    void removeInstance();
    Ticket* GenerateTicket(int floorNo, int spNo, int price, Vehicle *vehicle);
    void addTicket(Ticket ticket);
    void viewTicketHistory();
    Ticket* getTicketById(string ticketId);
};

#endif