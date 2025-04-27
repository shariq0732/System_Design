#include "PaymentStrategy.hpp"

class CreditCardPaymentStrategy: public PaymentStrategy
{
    public:

        void makePayment(int totalAmount);
        ~CreditCardPaymentStrategy();
};