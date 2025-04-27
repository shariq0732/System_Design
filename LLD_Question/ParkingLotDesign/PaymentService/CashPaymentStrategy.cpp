
#include "CashPaymentStrategy.hpp"

void CashPaymentStrategy::makePayment(int totalAmount)
{
    cout<<"Payment made using Cash: " << totalAmount << " ruppees"<< endl;
}
CashPaymentStrategy::~CashPaymentStrategy() {}