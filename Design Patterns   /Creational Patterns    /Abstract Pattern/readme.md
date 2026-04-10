# 🧩 Abstract Factory Pattern in C++

## 📌 Overview

This project demonstrates the **Abstract Factory Design Pattern** using a simple **UI Theme System** (Light & Dark) implemented in C++.

It highlights how **abstract methods** and **interfaces (abstract classes)** help achieve **loose coupling**, **flexibility**, and **scalability**.

---

## 🔷 What is an Abstract Method?

An **abstract method** is a method that is **declared but not implemented** in a base class.

In C++, abstract methods are created using **pure virtual functions**:

```cpp
virtual void render() = 0;
```

### 🔑 Key Points:

* Defined in an **abstract class (interface)**
* Has **no implementation**
* Must be **overridden** in derived classes
* A class with at least one pure virtual function becomes an **abstract class**

---

## 🔷 Objective of the Code

The goal of this project is to:

* ✔ Demonstrate the **Abstract Factory Pattern**
* ✔ Show how to create **families of related objects** (Button, TextBox)
* ✔ Enable switching between **Light and Dark themes at runtime**
* ✔ Avoid tight coupling between **client code and concrete classes**

---

## 🧱 Project Structure

### Abstract Products

* `Button`
* `TextBox`

These define abstract methods like:

```cpp
virtual void render() = 0;
```

---

### Concrete Products

* `LightButton`, `LightTextBox`
* `DarkButton`, `DarkTextBox`

Each class provides its own implementation of:

```cpp
void render() override;
```

---

### Abstract Factory

* `UIFactory`

Declares methods:

```cpp
virtual Button* createButton() = 0;
virtual TextBox* createTextBox() = 0;
```

---

### Concrete Factories

* `LightThemeFactory`
* `DarkThemeFactory`

These factories create specific product families.

---

### Client

* `Application`

Uses the factory without knowing the actual classes being created.

---

## 🔄 Code Flow

### Step-by-Step Execution:

1. **User Input**

   * User enters `"light"` or `"dark"`

2. **Factory Selection**

   * `getFactory()` returns:

     * `LightThemeFactory` OR
     * `DarkThemeFactory`

3. **Object Creation**

   * Factory creates:

     * `Button`
     * `TextBox`

4. **Polymorphic Behavior**

   * Calls `render()` on objects
   * Correct implementation executes based on theme

5. **Output Display**

   * UI components are rendered accordingly

---

## 🔁 How Abstract Methods Are Implemented

### Step 1: Declare Abstract Method

```cpp
class Button {
public:
    virtual void render() = 0; // Abstract Method
};
```

---

### Step 2: Implement in Derived Classes

```cpp
class LightButton : public Button {
public:
    void render() override {
        cout << "Rendering Light Button" << endl;
    }
};
```

---

### Step 3: Use via Base Class Pointer

```cpp
Button* btn = factory->createButton();
btn->render();  // Calls correct implementation
```

👉 This is **runtime polymorphism** in action.

---

## 🎯 Key Concepts Demonstrated

* ✔ **Abstraction** → Hiding implementation details
* ✔ **Polymorphism** → Same interface, different behavior
* ✔ **Encapsulation** → Object creation logic inside factories
* ✔ **Loose Coupling** → Client depends only on interfaces

---

## ✅ Advantages

* Easy to **switch themes**
* Promotes **clean architecture**
* Improves **maintainability**
* Follows **SOLID principles**

---

## ❌ Limitations

* Increases number of classes
* Harder to extend with new product types

---

## 🧠 Summary

The Abstract Factory Pattern uses **abstract methods** to define a contract for object creation.
Concrete classes implement these methods, allowing the system to remain **flexible and scalable**.

---

## 🚀 Example Output

### Input:

```
light
```

### Output:

```
Rendering Light Button
Rendering Light TextBox
```

---

## 📚 Conclusion

This implementation shows how **abstract methods (pure virtual functions)** form the backbone of the Abstract Factory Pattern, enabling dynamic object creation without exposing internal logic.

---
