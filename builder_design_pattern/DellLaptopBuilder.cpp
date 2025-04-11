#include "DellLaptopBuilder.hpp"



DellLaptopBuilder::DellLaptopBuilder(): LaptopBuilder() {}

DellLaptopBuilder::~DellLaptopBuilder() {}

void DellLaptopBuilder::buildName()
{
    this->laptop->setName("Dell Laptop");
}
void DellLaptopBuilder::buildKeyboard()
{
    this->laptop->setKeyboard("Dell Keyboard");
}
void DellLaptopBuilder::buildMouse()
{
    this->laptop->setMouse("Dell Mouse");
}
void DellLaptopBuilder::buildBarcode()
{
    this->laptop->setbarcode("DEL_12345-24234-ERTD23234");
}