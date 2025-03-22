#include "VehicleFactory.hpp"

int main()
{
    string vehicleName;
    cout<<"Please Enter the vehicle name to be created..." << endl;
    cin>>vehicleName;

    Ivehicle *vehicle = VehicleFactory::CreateVehicle(vehicleName);
    vehicle->CreateVehicle();
    
    delete vehicle;
    return 0;
}