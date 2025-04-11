#ifndef LAPTOP_BUILDER_H
#define LAPTOP_BUILDER_H

#include "Laptop.hpp"

class LaptopBuilder
{
    
    protected:
        Laptop *laptop;
    public:
        LaptopBuilder() {
            laptop = new Laptop();
        }

        virtual void buildName() = 0;
        virtual void buildKeyboard() = 0;
        virtual void buildMouse() = 0;
        virtual void buildBarcode() = 0;

        Laptop* buildLaptop()
        {
            return this->laptop;
        }

        virtual ~LaptopBuilder() {
        }
};

#endif