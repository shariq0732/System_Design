#include "PaymentStrategy.hpp"

class CashPaymentStrategy: public PaymentStrategy
{
    public:

        void makePayment(int totalAmount)
        {
            cout<<"Payment made using Cash: " << totalAmount << " ruppees"<< endl;
        }
        ~CashPaymentStrategy() {}
};