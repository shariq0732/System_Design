#ifndef PARKINGLOT_CPP
#define PARKINGLOT_CPP

#include <unordered_map>
#include "ParkingFloor.hpp"
#include "../EntranceAndExitPanel/EntrancePanel.hpp"
#include "../EntranceAndExitPanel/ExitPanel.hpp"
#include <mutex>


class ParkingLot
{   

    unordered_map<int, ParkingFloor> floorsMap;
    vector<EntrancePanel> entrancePanels;
    vector<ExitPanel> exitPanels;
    static int floorId;
    static mutex mtx;
    static ParkingLot* parkingLot;
    std::once_flag init_flag;

    ParkingLot() {}

    ParkingLot(const ParkingLot&) = delete;
    ParkingLot& operator=(const ParkingLot&) = delete;
    ParkingLot(ParkingLot&&) = delete;
    ParkingLot& operator=(ParkingLot&&) = delete;

    ParkingLot() {}
    ~ParkingLot() {}

    public:


        static ParkingLot* getInstance()
        {
            if(nullptr == parkingLot)
            {
                mtx.lock();
                if(nullptr == parkingLot)
                {
                    parkingLot = new ParkingLot();
                }
                mtx.unlock();
            }

            return parkingLot;
        }

        void destoryInstance()
        {
            delete this->parkingLot;
        }

        void AddParkingFloor(int smallPS, int compactPS, int largePS) 
        {
            lock_guard<mutex> lk(mtx);
            floorsMap[floorId] =  ParkingFloor(floorId, smallPS, compactPS, largePS);
            floorId++;
        }

        void AddEntrancePanel(EntrancePanel entrancePanel)
        {
            lock_guard<mutex> lk(mtx);
            this->entrancePanels.push_back(entrancePanel);
        }

        void AddExitPanel(ExitPanel exitPanel)
        {
            lock_guard<mutex> lk(mtx);
            this->exitPanels.push_back(exitPanel);
        }

        void removeEntrancePanel(EntrancePanel entrancePanel)
        {
            lock_guard<mutex> lk(mtx);
            for(vector<EntrancePanel>::iterator it = this->entrancePanels.begin(); it != this->entrancePanels.end(); it++)
            {
                if(it->getGateId() == entrancePanel.getGateId())
                {
                    this->entrancePanels.erase(it);
                    break;
                }
            }
        }

        void removeExitPanel(ExitPanel exitPanel)
        {
            lock_guard<mutex> lk(mtx);
            for(vector<ExitPanel>::iterator it = this->exitPanels.begin(); it != this->exitPanels.end(); it++)
            {
                if(it->getGateId() == exitPanel.getGateId())
                {
                    this->exitPanels.erase(it);
                    break;
                }
            }
        }

        void removeParkingFloor(int floorId)
        {
            lock_guard<mutex> lk(mtx);
            if(this->floorsMap.find(floorId) != this->floorsMap.end())
            {
                this->floorsMap.erase(floorId);
            }
        }

        bool canPark(Vehicle* vehicle)
        {
            lock_guard<mutex> lk(mtx);
            
            for(auto& it: floorsMap)
            {
                if(it.second.canPark(vehicle))
                    return true;
            }
            return false;
        }

        pair<pair<int,int>,int> parkVehicle(Vehicle* vehicle)
        {
            lock_guard<mutex> lk(mtx);
            for(auto& it: floorsMap)
            {
                if(it.second.canPark(vehicle))
                {
                    return it.second.parkVehicle(vehicle);
                }
            }
        }

        void vaccate(int floorId, int spNo, Vehicle* vehicle)
        {
            this->floorsMap[floorId].vaccate(spNo, vehicle);
        }

};

int ParkingLot::floorId = 0;
mutex ParkingLot::mtx;
ParkingLot* ParkingLot::parkingLot = nullptr;

#endif