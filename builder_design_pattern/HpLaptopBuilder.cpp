#include "HpLaptopBuilder.hpp"

HpLaptopBuilder::HpLaptopBuilder(): LaptopBuilder() {}
HpLaptopBuilder::~HpLaptopBuilder(){}

void HpLaptopBuilder::buildName()
{
    this->laptop->setName("Hp Laptop");
}
void HpLaptopBuilder::buildKeyboard()
{
    this->laptop->setKeyboard("Hp Keyboard");
}
void HpLaptopBuilder::buildMouse()
{
    this->laptop->setMouse("Hp Mouse");
}
void HpLaptopBuilder::buildBarcode()
{
    this->laptop->setbarcode("HP_12345-24234-ERTD23234");
}