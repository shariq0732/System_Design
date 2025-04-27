#include "DebitCardPaymentStrategy.hpp"

void DebitCardPaymentStrategy::makePayment(int totalAmount)
{
    cout<<"Payment made using debit card payment: " << totalAmount << " ruppees" << endl;
}
DebitCardPaymentStrategy::~DebitCardPaymentStrategy() {}