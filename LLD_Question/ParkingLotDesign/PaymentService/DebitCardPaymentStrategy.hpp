#include "PaymentStrategy.hpp"

class DebitCardPaymentStrategy: public PaymentStrategy
{
    public:

        void makePayment(int totalAmount)
        {
            cout<<"Payment made using debit card payment: " << totalAmount << " ruppees" << endl;
        }
        ~DebitCardPaymentStrategy() {}
};