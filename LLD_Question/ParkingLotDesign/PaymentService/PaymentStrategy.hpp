#ifndef PAYMENTSTRATEGY_H
#define PAYMENTSTRATEGY_H

#include <iostream>
using namespace std;

class PaymentStrategy
{
    public:

        PaymentStrategy() {}

        virtual void makePayment(int totalAmmount) = 0;

        virtual ~PaymentStrategy() {}
};

#endif