#include "NormalDrive.cpp"
#include "SpecialDrive.cpp"
#include "SportDrive.cpp"
#include "SportVehicle.cpp"
#include "OffRoadVehicle.cpp"
#include "PassengerVehicle.cpp"

int main()
{
    Vehicle *vehicle1 = new SportVehicle(new SportDrive());
    vehicle1->Drive();
    Vehicle *vehicle2 = new OffRoadVehicle(new SpecialDrive());
    vehicle2->Drive();
    Vehicle *vehicle3 = new PassengerVehicle(new NormalDrive());
    vehicle3->Drive();

    delete vehicle1, vehicle2, vehicle3;
    return 0;
}