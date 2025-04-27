#ifndef CASHPAYMENTSTRATEGY_H
#define CASHPAYMENTSTRATEGY_H

#include "PaymentStrategy.hpp"

class CashPaymentStrategy: public PaymentStrategy
{
    public:

        void makePayment(int totalAmount);
        ~CashPaymentStrategy();
};

#endif