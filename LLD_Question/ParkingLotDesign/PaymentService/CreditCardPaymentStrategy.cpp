#include "CreditCardPaymentStrategy.hpp"

void CreditCardPaymentStrategy::makePayment(int totalAmount)
{
    cout<<"Payment received using Credit card payment: " << totalAmount <<" ruppees" << endl;
}

CreditCardPaymentStrategy::~CreditCardPaymentStrategy() {}