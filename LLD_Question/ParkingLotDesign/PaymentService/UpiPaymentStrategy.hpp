
#include "PaymentStrategy.hpp"

class UpiPaymentStrategy: public PaymentStrategy
{
    public:

        void makePayment(int totalAmount)
        {
            cout<<"Payment made using UPI ID: " << totalAmount << " ruppees" << endl;
        }

        ~UpiPaymentStrategy() {}
};