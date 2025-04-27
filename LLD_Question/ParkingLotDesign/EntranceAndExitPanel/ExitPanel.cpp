
#include "ExitPanel.hpp"
#include "../ParkingLot/ParkingLot.hpp"

ExitPanel::ExitPanel(int gateId): Gate(gateId) 
{
    parkingLot = ParkingLot::getInstance();
    ticketService = TicketService::getInstance();
}


int ExitPanel::calculateTotalAmount(chrono::system_clock::time_point parkTime, chrono::system_clock::time_point exitTime)
{
    auto minutes = chrono::duration_cast<chrono::minutes>(exitTime - parkTime);
    int totalMinutes = minutes.count();
    
    //int totoalMinutes = static_cast<int>(std::ceil(totalMinutes));
    return totalMinutes;
}


void ExitPanel::ProcessPayment(double totalAmount)
{
    PaymentService *paymentService;
    while(true)
    {
        cout<<"Enter the option to choose payment option..." <<endl;
        cout<<"1. UPI" <<endl;
        cout<<"2. Credit Card" <<endl;
        cout<<"3. Debit Card" << endl;
        cout<<"4. Cash"<<endl;
        int option;
        cin>> option;
        if(option < 1 || option > 4)
        {
            cout<<"Invalied option Choose a valid option from the option list" << endl;
            continue; 
        }
        

        switch(option)
        {
            case 1:
                {
                    paymentService = PaymentFactory::getPaymentType("Upi");
                }
                break;
            case 2:
                {
                    paymentService = PaymentFactory::getPaymentType("Credit");
                }
                break;
            case 3:
                {
                    paymentService = PaymentFactory::getPaymentType("Debit");
                }
                break;
            case 4:
                {
                    paymentService = PaymentFactory::getPaymentType("Cash");
                }
                break;
        }
        break;

    }
    paymentService->ProcessPayment(totalAmount);
}


void ExitPanel::exitVehicleAndTakePayment(Ticket* ticket)
{
    Ticket* ticketHistory = this->ticketService->getTicketById(ticket->getTicketId());
    chrono::system_clock::time_point exitTime = chrono::system_clock::now();
    ticket->setVaccateDate(exitTime);
    ticketHistory->setVaccateDate(exitTime);

    int totalMinutes = calculateTotalAmount(ticket->getIssueTime(), exitTime);
    double price = ticket->getPrice();

    double totalAmount = (totalMinutes / 60)* price + static_cast<double>((totalMinutes%60)*((double)(price/60)));
    ProcessPayment(totalAmount);
    ticket->setTotalAmount(totalAmount);
    ticketHistory->setTotalAmount(totalAmount);
}

void ExitPanel::ProcessExit(Ticket* ticket)
{
    exitVehicleAndTakePayment(ticket);
}

