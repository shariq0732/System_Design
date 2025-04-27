#include "CashPaymentStrategy.hpp"
#include "DebitCardPaymentStrategy.hpp"
#include "UpiPaymentStrategy.hpp"
#include "CreditCardPaymentStrategy.hpp"

class PaymentService
{
    PaymentStrategy *paymentSt;
    public:

        PaymentService();
        PaymentService(PaymentStrategy *thePaymentSt);
        void ProcessPayment(double totalAmount);
        ~PaymentService();
};