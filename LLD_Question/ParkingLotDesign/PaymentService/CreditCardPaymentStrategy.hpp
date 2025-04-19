#include "PaymentStrategy.hpp"

class CreditCardPaymentStrategy: public PaymentStrategy
{
    public:

        void makePayment(int totalAmount)
        {
            cout<<"Payment received using Credit card payment: " << totalAmount <<" ruppees" << endl;
        }
        ~CreditCardPaymentStrategy() {}
};