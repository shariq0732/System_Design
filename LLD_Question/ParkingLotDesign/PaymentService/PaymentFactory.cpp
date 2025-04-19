#include "PaymentService.hpp"

class PaymentFactory
{
    public:

        static PaymentService* getPaymentType(string name)
        {
            if("Cash" == name)
            {
                return new PaymentService(new CashPaymentStrategy());
            }
            else if("Debit" == name)
            {
                return new PaymentService(new DebitCardPaymentStrategy());
            }
            else if("Credit" == name)
            {
                return new PaymentService(new CreditCardPaymentStrategy());
            }
            else
            {
                return new PaymentService(new UpiPaymentStrategy());
            }
        }
};