#ifndef CAR
#define CAR

#include <iostream>
using namespace std;

class Icar
{
    public:
        virtual void CreateCar() = 0;

        virtual ~Icar(){}
};

#endif