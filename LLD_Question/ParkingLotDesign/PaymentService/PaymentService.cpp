#include "PaymentService.hpp"

PaymentService::PaymentService(): paymentSt(nullptr) {}
PaymentService::PaymentService(PaymentStrategy *thePaymentSt): paymentSt(thePaymentSt) { }

void PaymentService::ProcessPayment(double totalAmount)
{
    this->paymentSt->makePayment(totalAmount);
}

PaymentService::~PaymentService() {
    delete paymentSt;
}