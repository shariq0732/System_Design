#ifndef Hp_LAPTOP_BUILDER_H
#define Hp_LAPTOP_BUILDER_H

#include "LaptopBuilder.hpp"

class HpLaptopBuilder: public LaptopBuilder
{

    public:
        HpLaptopBuilder();
        void buildName();
        void buildKeyboard();
        void buildMouse();
        void buildBarcode();

        ~HpLaptopBuilder();
};

#endif