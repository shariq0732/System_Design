#include "PaymentStrategy.hpp"

class DebitCardPaymentStrategy: public PaymentStrategy
{
    public:

        void makePayment(int totalAmount);
        ~DebitCardPaymentStrategy();
};