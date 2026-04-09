#include <iostream>
using namespace std;

//  Product Interface
class Notification {
public:
    virtual void send() = 0;
    virtual ~Notification() {}
};

//  Concrete Products
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

//  Creator (Factory Base Class)
class NotificationFactory {
public:
    // Factory Method
    virtual Notification* createNotification() = 0;

    void notifyUser() {
        Notification* n = createNotification(); // factory method call
        n->send();
        delete n;
    }

    virtual ~NotificationFactory() {}
};

//  Concrete Factories
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

//  Client Code
int main() {
    NotificationFactory* factory;

    factory = new EmailFactory();
    factory->notifyUser();

    factory = new SMSFactory();
    factory->notifyUser();

    delete factory;
    return 0;
}