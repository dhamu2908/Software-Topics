# 🟡 Factory Method Design Pattern (C++)

## 📌 What is Factory Method?

The **Factory Method Design Pattern** defines an interface for creating objects, but allows **subclasses to decide which object to instantiate**.

👉 It helps in **decoupling object creation from its usage**.

---

## 🎯 Objective of This Example

This project demonstrates how to:

* Create different types of **notifications (Email, SMS)**
* Avoid direct object creation (`new`) in client code
* Use **polymorphism** to decide object creation at runtime

---

## 🧠 Problem Without Factory Method

```cpp
if (type == "email")
    notification = new EmailNotification();
else if (type == "sms")
    notification = new SMSNotification();
```

❌ Issues:

* Tight coupling
* Hard to extend
* Violates Open/Closed Principle

---

## ✅ Solution Using Factory Method

We delegate object creation to **subclasses (factories)**.

---

## 🏗️ Code Implementation

```cpp
#include <iostream>
using namespace std;

// Product Interface
class Notification {
public:
    virtual void send() = 0;
    virtual ~Notification() {}
};

// Concrete Products
class EmailNotification : public Notification {
public:
    void send() override {
        cout << "Sending Email Notification\n";
    }
};

class SMSNotification : public Notification {
public:
    void send() override {
        cout << "Sending SMS Notification\n";
    }
};

// Creator (Factory Base Class)
class NotificationFactory {
public:
    virtual Notification* createNotification() = 0;

    void notifyUser() {
        Notification* n = createNotification();
        n->send();
        delete n;
    }

    virtual ~NotificationFactory() {}
};

// Concrete Factories
class EmailFactory : public NotificationFactory {
public:
    Notification* createNotification() override {
        return new EmailNotification();
    }
};

class SMSFactory : public NotificationFactory {
public:
    Notification* createNotification() override {
        return new SMSNotification();
    }
};

// Client Code
int main() {
    NotificationFactory* factory;

    factory = new EmailFactory();
    factory->notifyUser();

    factory = new SMSFactory();
    factory->notifyUser();

    delete factory;
    return 0;
}
```

---

## 🔍 How This Code Follows Factory Method

### ✅ 1. Product Interface

```cpp
class Notification
```

* Defines a common interface for all objects

---

### ✅ 2. Concrete Products

```cpp
EmailNotification, SMSNotification
```

* Actual implementations

---

### ✅ 3. Factory Method

```cpp
virtual Notification* createNotification() = 0;
```

* Declared in base class
* Implemented in subclasses

---

### ✅ 4. Concrete Factories

```cpp
EmailFactory → creates EmailNotification  
SMSFactory → creates SMSNotification  
```

👉 Subclasses decide **what object to create**

---

### ✅ 5. Polymorphism

```cpp
factory->notifyUser();
```

👉 Calls correct object creation at runtime

---

## 🔄 Execution Flow

1. Client selects a factory (EmailFactory / SMSFactory)
2. Calls `notifyUser()`
3. Inside base class → calls `createNotification()`
4. Subclass creates correct object
5. `send()` method is executed

---

## 🖥️ Output

```text
Sending Email Notification
Sending SMS Notification
```

---

## 🔥 Key Advantages

* Loose coupling
* Easy to extend (add new notification types)
* Follows Open/Closed Principle
* Uses polymorphism instead of conditionals

---

## ❌ Disadvantages

* More classes → increased complexity
* Slight learning curve

---

## 🚀 How to Extend

To add a new notification type:

```cpp
class PushNotification : public Notification {
public:
    void send() override {
        cout << "Sending Push Notification\n";
    }
};

class PushFactory : public NotificationFactory {
public:
    Notification* createNotification() override {
        return new PushNotification();
    }
};
```

👉 No changes needed in existing code ✅

---

## 🧠 Key Takeaway

> Factory Method allows object creation to be delegated to subclasses, enabling flexible and scalable design.

---

## 📌 Summary

| Feature         | Description             |
| --------------- | ----------------------- |
| Pattern Type    | Creational              |
| Object Creation | Delegated to subclasses |
| Key Concept     | Polymorphism            |
| Benefit         | Loose coupling          |

---
