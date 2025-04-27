

#include "ParkingLot.hpp"
#include "../EntranceAndExitPanel/EntrancePanel.hpp"
#include "../EntranceAndExitPanel/ExitPanel.hpp"

int ParkingLot::floorId = 0;
mutex ParkingLot::mtx;
ParkingLot* ParkingLot::parkingLot = nullptr;

ParkingLot::ParkingLot() {}
ParkingLot::~ParkingLot() {}

ParkingLot* ParkingLot::getInstance()
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

void ParkingLot::destoryInstance()
{
    delete this->parkingLot;
}

void ParkingLot::AddParkingFloor(int smallPS, int compactPS, int largePS) 
{
    lock_guard<mutex> lk(mtx);
    floorsMap[floorId] =  ParkingFloor(floorId, smallPS, compactPS, largePS);
    floorId++;
}

void ParkingLot::AddEntrancePanel(EntrancePanel entrancePanel)
{
    lock_guard<mutex> lk(mtx);
    this->entrancePanels.push_back(entrancePanel);
}

void ParkingLot::AddExitPanel(ExitPanel exitPanel)
{
    lock_guard<mutex> lk(mtx);
    this->exitPanels.push_back(exitPanel);
}

void ParkingLot::removeEntrancePanel(EntrancePanel entrancePanel)
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

void ParkingLot::removeExitPanel(ExitPanel exitPanel)
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

void ParkingLot::removeParkingFloor(int floorId)
{
    lock_guard<mutex> lk(mtx);
    if(this->floorsMap.find(floorId) != this->floorsMap.end())
    {
        this->floorsMap.erase(floorId);
        this->floorId--;
    }
}

bool ParkingLot::canPark(Vehicle* vehicle)
{
    lock_guard<mutex> lk(mtx);
    
    for(auto& it: floorsMap)
    {
        if(it.second.canPark(vehicle))
            return true;
    }
    return false;
}

pair<pair<int,int>,int> ParkingLot::parkVehicle(Vehicle* vehicle)
{
    lock_guard<mutex> lk(mtx);
    for(auto& it: floorsMap)
    {
        if(it.second.canPark(vehicle))
        {
            return it.second.parkVehicle(vehicle);
        }
    }
    return {{-1,-1},-1};
}

void ParkingLot::vaccate(int floorId, int spNo, Vehicle* vehicle)
{
    this->floorsMap[floorId].vaccate(spNo, vehicle);
}

EntrancePanel* ParkingLot::getEntrancePanel(int gateId)
{
    for(auto& it: this->entrancePanels)
    {
        if(it.getGateId() == gateId)
            return &it;
    }
    return nullptr;
}

ExitPanel* ParkingLot::getExitPane(int gateId)
{   
    for(auto& it : this->exitPanels)
    {
        if(it.getGateId() == gateId)
            return &it;
    }
    return nullptr;

}
