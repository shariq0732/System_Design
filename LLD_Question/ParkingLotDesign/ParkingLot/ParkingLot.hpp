#ifndef PARKINGLOT_HPP
#define PARKINGLOT_HPP

#include <unordered_map>
#include "ParkingFloor.hpp"
#include <mutex>

class EntrancePanel;
class ExitPanel;

class ParkingLot
{   

    unordered_map<int, ParkingFloor> floorsMap;
    vector<EntrancePanel> entrancePanels;
    vector<ExitPanel> exitPanels;
    static int floorId;
    static mutex mtx;
    static ParkingLot* parkingLot;
    std::once_flag init_flag;

    ParkingLot(const ParkingLot&) = delete;
    ParkingLot& operator=(const ParkingLot&) = delete;
    ParkingLot(ParkingLot&&) = delete;
    ParkingLot& operator=(ParkingLot&&) = delete;

    ParkingLot();
    ~ParkingLot();

    public:


        static ParkingLot* getInstance();
        void destoryInstance();
        void AddParkingFloor(int smallPS, int compactPS, int largePS);
        void AddEntrancePanel(EntrancePanel entrancePanel);
        void AddExitPanel(ExitPanel exitPanel);
        void removeEntrancePanel(EntrancePanel entrancePanel);
        void removeExitPanel(ExitPanel exitPanel);
        void removeParkingFloor(int floorId);
        EntrancePanel* getEntrancePanel(int gateId);
        ExitPanel* getExitPane(int gateId);
        bool canPark(Vehicle* vehicle);
        pair<pair<int,int>,int> parkVehicle(Vehicle* vehicle);
        void vaccate(int floorId, int spNo, Vehicle* vehicle);
};

#endif