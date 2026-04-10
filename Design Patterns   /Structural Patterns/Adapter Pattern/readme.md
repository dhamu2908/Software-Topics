# 🔌 Adapter Design Pattern in C++

## 📖 Overview

The **Adapter Design Pattern** is a structural design pattern that allows two incompatible interfaces to work together. It acts as a bridge between an existing class (Adaptee) and the expected interface (Target).

This project demonstrates real-world use cases of the Adapter Pattern using C++.

---

## 🎯 Problem Statement

In real-world applications, we often need to integrate:

* Legacy systems
* Third-party libraries
* External APIs

These systems may have **different interfaces**, making direct communication impossible.

---

## 💡 Solution

The Adapter Pattern introduces a **wrapper (Adapter)** that converts one interface into another, enabling seamless integration without modifying existing code.

---

## 🧩 Structure

* **Target** → Expected interface (used by client)
* **Adaptee** → Existing class with incompatible interface
* **Adapter** → Converts Target calls to Adaptee

---

## ⚙️ Example: Payment Gateway Integration

### 🔴 Without Adapter Pattern

```cpp
StripeAPI stripe;
stripe.makePayment(100);  // Direct usage
```

### ❌ Problems:

* Tight coupling with Stripe
* Cannot easily switch to another provider (e.g., PayPal)
* Violates **Open/Closed Principle**
* Code becomes hard to maintain and extend

---

### 🟢 With Adapter Pattern

```cpp
PaymentProcessor* payment = new StripeAdapter();
payment->pay(100);
```

---

## 💻 Full Code Example

```cpp
#include <iostream>
using namespace std;

// Target Interface
class PaymentProcessor {
public:
    virtual void pay(double amount) = 0;
};

// Adaptee (Stripe API)
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
        stripe.makePayment(amount);
    }
};

// Client
int main() {
    PaymentProcessor* payment = new StripeAdapter();
    payment->pay(100.5);
    return 0;
}
```

---

## 🔄 How Adapter Pattern Works (Step-by-Step)

1. The **client** calls the `pay()` method (Target interface)
2. The **Adapter** receives this request
3. The Adapter translates the request into `makePayment()`
4. The **Adaptee (StripeAPI)** executes the request
5. The result is returned to the client

👉 The client is unaware of the conversion process.

---

## ⚖️ Without vs With Adapter Pattern

| Feature         | Without Adapter   | With Adapter   |
| --------------- | ----------------- | -------------- |
| Flexibility     | Low               | High           |
| Code Reuse      | Limited           | High           |
| Maintainability | Poor              | Good           |
| Coupling        | Tight             | Loose          |
| Extensibility   | Difficult         | Easy           |

---

## 🚀 Benefits

* ✅ Reuse existing code without modification
* ✅ Improves flexibility and scalability
* ✅ Follows SOLID principles
* ✅ Decouples client from implementation

---

## ⚠️ Drawbacks

* ❌ Adds extra layer of abstraction
* ❌ Slight increase in complexity

---

## 🧠 When to Use

* When integrating **third-party libraries**
* When working with **legacy systems**
* When interfaces are **incompatible**

---

## 🧾 Conclusion

The Adapter Pattern is a powerful structural pattern that helps bridge incompatible interfaces. It promotes clean architecture, improves maintainability, and enables seamless integration of external components into modern systems.

---
