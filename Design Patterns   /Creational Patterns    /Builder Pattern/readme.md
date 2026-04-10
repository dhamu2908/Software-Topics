# 🏗️ Builder Pattern in C++ – Real-World Example (HTTP Request)

## 📌 Overview

This project demonstrates the **Builder Design Pattern** in C++ using a real-world example: constructing an **HTTP Request**.

In real applications (like APIs or backend systems), HTTP requests often include multiple optional parameters such as headers, body, method, etc. Managing this with traditional constructors quickly becomes messy.

👉 This implementation shows how the Builder Pattern solves that problem cleanly.

---

## 🎯 Objective of the Code

The objective is to:

* Create a flexible way to construct an `HttpRequest` object
* Handle both **required** and **optional** parameters efficiently
* Improve **code readability and maintainability**
* Avoid constructor overload complexity

---

## ❌ Problem Without Builder Pattern

Without the Builder Pattern, object creation might look like this:

```cpp
HttpRequest("https://api.example.com", "POST", headers, body);
```

### Issues:

* ❓ Hard to remember parameter order
* 😵 Difficult to read and understand
* 🔁 Requires multiple overloaded constructors
* 🐞 Error-prone when dealing with optional fields
* 🚫 Poor scalability when adding new parameters

---

## ✅ Solution: Builder Pattern

Using the Builder Pattern:

```cpp
HttpRequest request = HttpRequest::Builder("https://api.example.com")
                            .setMethod("POST")
                            .addHeader("Content-Type", "application/json")
                            .addHeader("Authorization", "Bearer token123")
                            .setBody("{\"name\":\"John\"}")
                            .build();
```

---

## 🚀 How Builder Pattern Helps in This Code

### 1. ✔ Step-by-Step Object Construction

You build the object gradually instead of passing everything at once.

---

### 2. ✔ Improved Readability

The code is self-explanatory and easy to understand:

```cpp
.setMethod("POST").addHeader(...).setBody(...)
```

---

### 3. ✔ Handles Optional Parameters Gracefully

You only set what you need—no unnecessary arguments.

---

### 4. ✔ Avoids Constructor Overloading

No need for multiple constructors for different combinations of parameters.

---

### 5. ✔ Default Values Support

For example:

```cpp
string method = "GET";
```

If not specified, defaults are used.

---

### 6. ✔ Fluent Interface (Method Chaining)

Each method returns the builder object:

```cpp
return *this;
```

This enables chaining.

---

## ⚖️ Comparison

| Feature                | Without Builder ❌ | With Builder ✅ |
| ---------------------- | ----------------- | -------------- |
| Readability            | Poor              | Excellent      |
| Flexibility            | Low               | High           |
| Maintainability        | Difficult         | Easy           |
| Optional Fields        | Hard to manage    | Easy to handle |
| Constructor Complexity | High              | Minimal        |

---

## 🧠 Key Concept

> The Builder Pattern separates **object construction** from its **representation**, allowing the same construction process to create different representations.

---

## 📦 Use Cases

* API request builders
* Configuration objects
* Complex object creation (e.g., UI components, database queries)
* Immutable objects

---

## 🏁 Conclusion

The Builder Pattern provides a clean and scalable way to construct complex objects. In this example, it transforms a confusing and error-prone constructor-based approach into a **readable, flexible, and maintainable solution**.

---

