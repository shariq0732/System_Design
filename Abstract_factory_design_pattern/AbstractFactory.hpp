#ifndef ABSTRACT_FACTORY
#define ABSTRACT_FACTORY


#include "IvehicleFactory.hpp"
#include "HyundaiFactory.hpp"
#include "ToyottaFactory.hpp"
#include <string>

class AbstractFactory
{
    public:

        static IVehicleFactory* CreateFactory(string factoryName);
};

#endif