#ifndef LAPTOP_H
#define LAPTOP_H

#include <iostream>
#include <string>
using namespace std;

class Laptop
{
    string name;
    string mouse;
    string keyboard;
    string barcode;

    public:
        Laptop();
        void setName(string theName);
        void setMouse(string theMouse);
        void setKeyboard(string theKeyboard);
        void setbarcode(string theBarcode);
        void show();
};

#endif