
#include "PaymentStrategy.hpp"

class UpiPaymentStrategy: public PaymentStrategy
{
    public:

        void makePayment(int totalAmount);
        ~UpiPaymentStrategy();
};