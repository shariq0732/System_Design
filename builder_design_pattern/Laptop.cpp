#include "Laptop.hpp"

Laptop::Laptop() {}

void Laptop::setName(string theName)
{
    this->name = theName;
}

void Laptop::setMouse(string theMouse)
{
    this->mouse = theMouse;
}

void Laptop::setbarcode(string theBarcode)
{
    this->barcode = theBarcode;
}

void Laptop::setKeyboard(string theKeyboard)
{
    this->keyboard = theKeyboard;
}

void Laptop::show()
{
    cout<<"......Laptop detail.....";
    cout<<  endl << endl << this->name << endl << this->barcode <<endl << this->mouse << endl << this->keyboard << endl <<endl;
}