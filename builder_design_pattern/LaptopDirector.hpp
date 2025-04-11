#ifndef LAPTOP_DIRECTOR_H
#define LAPTOP_DIRECTOR_H

#include "DellLaptopBuilder.hpp"
#include "HpLaptopBuilder.hpp"
class LaptopDirector
{
    LaptopBuilder *builder;
    public:
        LaptopDirector();

        LaptopDirector(LaptopBuilder* theBuilder);
        Laptop* CreateDellLaptp();
        Laptop* CreateHpLaptop();

        ~LaptopDirector();
};

#endif