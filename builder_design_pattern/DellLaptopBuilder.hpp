#ifndef DELL_LAPTOP_BUILDER_H
#define DELL_LAPTOP_BUILDER_H

#include "LaptopBuilder.hpp"

class DellLaptopBuilder: public LaptopBuilder
{

    public:
        DellLaptopBuilder();
        void buildName();
        void buildKeyboard();
        void buildMouse();
        void buildBarcode();
        
        ~DellLaptopBuilder();
};

#endif