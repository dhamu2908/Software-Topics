#include <iostream>
#include <vector>
using namespace std;

// Component
class Employee {
public:
    virtual void showDetails() = 0;
    virtual ~Employee() {}
};

// Leaf
class Developer : public Employee {
    string name;
public:
    Developer(string name) : name(name) {}

    void showDetails() override {
        cout << "Developer: " << name << endl;
    }
};

// Leaf
class Designer : public Employee {
    string name;
public:
    Designer(string name) : name(name) {}

    void showDetails() override {
        cout << "Designer: " << name << endl;
    }
};

// Composite
class Manager : public Employee {
    string name;
    vector<Employee*> team;

public:
    Manager(string name) : name(name) {}

    void add(Employee* emp) {
        team.push_back(emp);
    }

    void showDetails() override {
        cout << "Manager: " << name << endl;
        for (auto emp : team) {
            emp->showDetails(); // recursive call
        }
    }
};

// Client
int main() {
    // Leaf objects
    Employee* dev1 = new Developer("Alice");
    Employee* dev2 = new Developer("Bob");
    Employee* des1 = new Designer("Charlie");

    // Composite object
    Manager* manager1 = new Manager("David");
    manager1->add(dev1);
    manager1->add(dev2);
    manager1->add(des1);

    // Higher-level composite
    Manager* director = new Manager("Emma");
    director->add(manager1);

    // Uniform call
    director->showDetails();

    return 0;
}
