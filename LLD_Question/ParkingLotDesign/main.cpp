#include "ParkingLot/ParkingLot.hpp"
#include "EntranceAndExitPanel/EntrancePanel.hpp"
#include "EntranceAndExitPanel/ExitPanel.hpp"
#include <chrono>
#include <thread>
using namespace std;

int main()
{
    ParkingLot *parkingLot = ParkingLot::getInstance();
    parkingLot->AddParkingFloor(200, 250, 100);
    parkingLot->AddParkingFloor(200, 250, 100);
    parkingLot->AddParkingFloor(200, 250, 100);
    parkingLot->AddParkingFloor(200, 250, 100);

    parkingLot->AddEntrancePanel(EntrancePanel(0));
    parkingLot->AddExitPanel(ExitPanel(0));
    parkingLot->AddEntrancePanel(EntrancePanel(1));
    parkingLot->AddExitPanel(ExitPanel(1));
    parkingLot->AddEntrancePanel(EntrancePanel(2));
    parkingLot->AddExitPanel(ExitPanel(2));

    EntrancePanel *entrancePanel = nullptr;
    ExitPanel* exitPanel = nullptr;

    while(true)
    {
        int gateId;
        cout<<"Enter the Gate Id"<<endl;
        cin >> gateId;
        entrancePanel = parkingLot->getEntrancePanel(gateId);
        if(entrancePanel == nullptr)
        {
            cout<<"invalued gate Id" <<endl;
            continue;
        }
        exitPanel = parkingLot->getExitPane(gateId);
        break;
    }
    
    
    cout<<"************************** WELCOME TO PARKING LOT **************************" << endl;

    
    Ticket* ticket = entrancePanel->ProcessEntrance();
    if(ticket != nullptr)
    {
        this_thread::sleep_for(chrono::minutes(2));
        exitPanel->ProcessExit(ticket);
        ticket->print();
    }

}