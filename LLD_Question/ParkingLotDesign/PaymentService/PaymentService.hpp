#include "CashPaymentStrategy.hpp"
#include "DebitCardPaymentStrategy.hpp"
#include "UpiPaymentStrategy.hpp"
#include "CreditCardPaymentStrategy.hpp"

class PaymentService
{
    PaymentStrategy *paymentSt;
    public:

        PaymentService(): paymentSt(nullptr) {}
        PaymentService(PaymentStrategy *thePaymentSt): paymentSt(thePaymentSt) { }

        void ProcessPayment(int totalAmount)
        {
            this->paymentSt->makePayment(totalAmount);
        }

        ~PaymentService() {
            delete paymentSt;
        }
};