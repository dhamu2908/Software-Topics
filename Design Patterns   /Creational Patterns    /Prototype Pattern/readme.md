# 🧬 Prototype Design Pattern in C++

## 📌 Overview

The **Prototype Design Pattern** is a **creational design pattern** that allows you to create new objects by **copying an existing object (prototype)** instead of creating them from scratch.

This project demonstrates how to implement the Prototype Pattern in **C++** using:

* Abstract base classes
* Virtual `clone()` method
* Copy constructors

---

## 🚀 Why Use Prototype Pattern?

Creating objects can sometimes be:

* ⏱️ Expensive (complex initialization)
* 🔁 Repetitive (many similar objects)

Instead of building objects again and again, we:

> ✅ Clone an existing object and modify it if needed

---

## 🧠 Concept

The pattern works by:

1. Defining a common interface with a `clone()` method
2. Implementing this method in concrete classes
3. Creating new objects by copying existing ones

---

## 🏗️ Class Structure

```
          +------------------+
          |      Shape       |  <-- Prototype Interface
          |------------------|
          | + clone()        |
          | + draw()         |
          +--------+---------+
                   |
        -------------------------
        |                       |
+---------------+     +------------------+
|    Circle     |     |    Rectangle     |
|---------------|     |------------------|
| radius        |     | width, height    |
| clone()       |     | clone()          |
| draw()        |     | draw()           |
+---------------+     +------------------+
```

---

## 🔄 Code Flow (Step-by-Step)

### 1. Create Prototype Interface

* `Shape` defines a pure virtual `clone()` method
* Ensures all derived classes support cloning

### 2. Implement Concrete Prototypes

* `Circle` and `Rectangle` inherit from `Shape`
* Each implements:

  * `clone()` → returns a copy using copy constructor
  * `draw()` → prints object details

### 3. Use Copy Constructor

* When `clone()` is called:

```cpp
return new Circle(*this);
```

* This copies the current object

### 4. Client Code

* Create original objects (prototypes)
* Clone them instead of creating new ones

```cpp
Shape* circle2 = circle1->clone();
```

---

## 🔍 How This Follows Prototype Pattern

| Prototype Principle        | Implementation                |
| -------------------------- | ----------------------------- |
| Define clone method        | `virtual Shape* clone()`      |
| Copy existing object       | `new Circle(*this)`           |
| Avoid direct instantiation | Client uses `clone()`         |
| Polymorphic cloning        | Base class pointer (`Shape*`) |

---

## 💻 Example Output

```
Circle with radius: 10
Rectangle: 5 x 8
```

---

## ⚠️ Shallow vs Deep Copy

### 🔹 Shallow Copy

* Copies values and references
* May cause shared data issues

### 🔹 Deep Copy

* Fully duplicates memory
* Needed when using pointers or dynamic allocation

---

## 🛠️ Improvements (Optional)

* Use `std::unique_ptr` instead of raw pointers
* Implement a **Prototype Registry (cache)**
* Add more shapes dynamically

---

## 📁 File Structure

```
prototype-pattern/
│
├── main.cpp
├── README.md
```

---

## ▶️ How to Run

```bash
g++ main.cpp -o prototype
./prototype
```

---

## 📚 Key Takeaway

> The Prototype Pattern creates new objects by cloning existing ones, improving performance and flexibility when object creation is costly.

---

## 🤝 Contributing

Feel free to fork this repo and improve:

* Add new prototypes
* Implement deep copy examples
* Optimize memory management

---

## ⭐ If you found this helpful, give it a star!
