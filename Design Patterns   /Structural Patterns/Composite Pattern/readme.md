# 📦 Composite Design Pattern (C++ Example)

## 🧠 Overview

The **Composite Design Pattern** is a structural design pattern that allows you to treat **individual objects (leaves)** and **groups of objects (composites)** uniformly through a common interface.

It is especially useful when dealing with **tree-like hierarchical structures**, such as:

* Company organization
* File systems
* UI components

---

## 🏢 Real-World Example Used Here

We modeled a **company hierarchy**:

* **Employee (Component)** → common interface
* **Developer, Designer (Leaf)** → individual employees
* **Manager (Composite)** → manages employees or other managers

---

## 🧩 Structure of the Code

### 1. Component (`Employee`)

```cpp
class Employee {
public:
    virtual void showDetails() = 0;
};
```

* Defines a **common interface**
* All objects (leaf + composite) implement this

---

### 2. Leaf Classes (`Developer`, `Designer`)

```cpp
class Developer : public Employee { ... };
class Designer : public Employee { ... };
```

* Represent **individual objects**
* Do not contain children
* Directly implement behavior (`showDetails()`)

---

### 3. Composite Class (`Manager`)

```cpp
class Manager : public Employee {
    vector<Employee*> team;
};
```

* Can store **multiple Employee objects**
* Can contain both:

  * Leaves (Developer, Designer)
  * Other composites (Managers)

---

### 4. Client (`main()`)

* Builds the hierarchy
* Calls methods **without worrying about object type**

---

## 🔄 Code Flow (Step-by-Step)

### Step 1: Create Leaf Objects

```cpp
Employee* dev1 = new Developer("Alice");
Employee* dev2 = new Developer("Bob");
Employee* des1 = new Designer("Charlie");
```

* These are **individual employees**
* No children inside them

---

### Step 2: Create a Manager (Composite)

```cpp
Manager* manager1 = new Manager("David");
manager1->add(dev1);
manager1->add(dev2);
manager1->add(des1);
```

* Manager stores a **list of employees**
* This forms a **subtree**

---

### Step 3: Create Higher-Level Composite

```cpp
Manager* director = new Manager("Emma");
director->add(manager1);
```

* A manager can contain another manager
* Builds a **tree structure**

---

### Step 4: Execute Operation

```cpp
director->showDetails();
```

### What Happens Internally:

1. `director->showDetails()` is called

2. It prints:

   ```
   Manager: Emma
   ```

3. Then it loops through its team:

   * Calls `manager1->showDetails()`

4. `manager1` prints:

   ```
   Manager: David
   ```

5. Then calls:

   * `dev1->showDetails()`
   * `dev2->showDetails()`
   * `des1->showDetails()`

6. Each leaf prints its own details

👉 This is **recursive delegation**

---

## 🌳 How Composite Pattern Works Here

### Key Idea: Uniform Treatment

All objects share:

```cpp
Employee* obj;
obj->showDetails();
```

We don’t care if:

* `obj` is a **Developer**
* `obj` is a **Manager**

---

### 🔁 Recursive Behavior

* **Leaf** → executes operation directly
* **Composite** → forwards operation to children

```cpp
for (auto emp : team) {
    emp->showDetails();
}
```

👉 This creates a **tree traversal**

---

## 🚫 What Happens Without Composite Pattern?

Without this pattern, you would likely:

### ❌ Use Conditional Logic Everywhere

```cpp
if (type == "Developer") { ... }
else if (type == "Manager") { ... }
```

### ❌ Separate Handling for Groups vs Individuals

* Different functions for:

  * Single employee
  * Group of employees

### ❌ Tight Coupling

* Client must know:

  * Who is a manager
  * Who is a developer
  * Who has children

### ❌ No Recursive Structure

* Hard to represent hierarchy cleanly

---

## ✅ With Composite Pattern

| Feature          | Benefit                     |
| ---------------- | --------------------------- |
| Common Interface | Treat all objects uniformly |
| Tree Structure   | Naturally models hierarchy  |
| Recursion        | Simplifies operations       |
| Extensibility    | Easy to add new roles       |

---

## 🧠 Key Takeaway

> “Composite lets you treat a single object and a group of objects the same way.”

In this example:

* Calling `showDetails()` works for:

  * One employee ✅
  * Entire organization ✅

---

## 🔚 Conclusion

The Composite Pattern:

* Simplifies hierarchical designs
* Eliminates complex conditionals
* Makes code scalable and maintainable

---
