
#include "UpiPaymentStrategy.hpp"
void UpiPaymentStrategy::makePayment(int totalAmount)
{
    cout<<"Payment made using UPI ID: " << totalAmount << " ruppees" << endl;
}

UpiPaymentStrategy::~UpiPaymentStrategy() {}