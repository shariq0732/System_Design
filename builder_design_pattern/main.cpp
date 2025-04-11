#include "LaptopDirector.hpp"

int main()
{

    LaptopDirector *dellDirector = new LaptopDirector(new DellLaptopBuilder());
    LaptopDirector *hpDirector = new LaptopDirector(new HpLaptopBuilder());

    Laptop *dellLaptop = dellDirector->CreateDellLaptp();
    Laptop *hpLaptop = hpDirector->CreateHpLaptop();

    dellLaptop->show();
    hpLaptop->show();

    delete dellDirector;
    delete hpDirector;
    delete dellLaptop;
    delete hpLaptop;
    return 0;
}

