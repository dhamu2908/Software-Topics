#include <iostream>
using namespace std;

// Target Interface (what system expects)
class PaymentProcessor {
public:
    virtual void pay(double amount) = 0;
};

// Adaptee (existing Stripe system with different interface)
class StripeAPI {
public:
    void makePayment(double amount) {
        cout << "Payment of $" << amount << " made using Stripe\n";
    }
};

// Adapter
class StripeAdapter : public PaymentProcessor {
private:
    StripeAPI stripe;
public:
    void pay(double amount) override {
        stripe.makePayment(amount); // adapting call
    }
};

// Client
int main() {
    PaymentProcessor* payment = new StripeAdapter();
    payment->pay(100.50);
    return 0;
}
