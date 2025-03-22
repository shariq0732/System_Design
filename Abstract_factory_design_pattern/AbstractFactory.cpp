#include "AbstractFactory.hpp"

IVehicleFactory* AbstractFactory::CreateFactory(string factoryName)
{
    IVehicleFactory* factory = nullptr;

    if("Hyundai" == factoryName)
    {
        factory =  new HyundaiFactory();
    }
    else if("Toyotta" == factoryName)
    {
        factory =  new ToyottaFactory();
    }
    else
    {
        cout<<"Invalied Factory Type" << endl;
        
    }

    return factory;
}