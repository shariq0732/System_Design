#include "LaptopDirector.hpp"

LaptopDirector::LaptopDirector()
{

}

LaptopDirector::LaptopDirector(LaptopBuilder* theBuilder)
{
    this->builder = theBuilder;
}

LaptopDirector::~LaptopDirector()
{
    delete this->builder;
}

Laptop* LaptopDirector::CreateDellLaptp()
{
    this->builder->buildName();
    this->builder->buildBarcode();
    this->builder->buildKeyboard();
    this->builder->buildMouse();
    return this->builder->buildLaptop();
}
Laptop* LaptopDirector::CreateHpLaptop()
{
    this->builder->buildName();
    this->builder->buildBarcode();
    this->builder->buildKeyboard();
    this->builder->buildMouse();
    return this->builder->buildLaptop();
}