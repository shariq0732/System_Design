#ifndef EXITPANEL_H
#define EXITPANEL_H

#include <iostream>
#include "Gate.hpp"
#include "../ticket/Ticket.hpp"
#include "../ParkingLot/ParkingLot.cpp"
#include "../PaymentService/PaymentFactory.cpp"
#include <cmath>
using namespace std;

class ExitPanel: public Gate
{  
   
    ParkingLot *parkingLot;

    public:
        ExitPanel(int gateId): Gate(gateId) 
        {
            parkingLot = ParkingLot::getInstance();
        }


        int calculateTotalAmount(chrono::system_clock::time_point parkTime, chrono::system_clock::time_point exitTime)
        {
            auto minutes = chrono::duration_cast<chrono::minutes>(exitTime - parkTime);
            int totalMinutes = minutes.count();
            
            int hours = static_cast<int>(std::ceil(totalMinutes / 60.0));
            return hours;
        }


        void ProcessPayment(int totalAmount)
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


        void exitVehicleAndTakePayment(Ticket* ticket)
        {
            chrono::system_clock::time_point exitTime = chrono::system_clock::now();
            ticket->setVaccateDate(exitTime);

            int totalHours = calculateTotalAmount(ticket->getIssueTime(), exitTime);
            int price = ticket->getPrice();

            long long totalAmount = price*totalHours;
            ProcessPayment(totalAmount);
            ticket->setTotalAmount(totalAmount);
        }

};

#endif