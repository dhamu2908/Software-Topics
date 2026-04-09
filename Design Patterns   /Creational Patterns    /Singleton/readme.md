#  Singleton Design Pattern (C++)

## 📌 What is Singleton?

The **Singleton Design Pattern** ensures that:

* Only **one instance** of a class exists
* A **global access point** is provided to access that instance

It is commonly used when exactly one object is needed to coordinate actions across the system.

---

##  Real-World Use Cases

* Logging system
* Database connection manager
* Configuration manager
* Cache system

---

##  Implementation (C++)

```cpp
#include <iostream>
#include <fstream>
using namespace std;

class Logger {
private:
    static Logger* instance;
    ofstream logFile;

    Logger() {
        logFile.open("log.txt", ios::app);
        cout << "Logger initialized\n";
    }

public:
    static Logger* getInstance() {
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }

    void log(string message) {
        logFile << message << endl;
    }
};

Logger* Logger::instance = nullptr;

int main() {
    Logger* logger1 = Logger::getInstance();
    logger1->log("First message");

    Logger* logger2 = Logger::getInstance();
    logger2->log("Second message");

    cout << (logger1 == logger2) << endl;

    return 0;
}
```

---

##  How this code follows Singleton Pattern

###  1. Private Constructor

```cpp
Logger()
```

* Prevents object creation outside the class

---

###  2. Static Instance Variable

```cpp
static Logger* instance;
```

* Stores the single object

---

###  3. Global Access Method

```cpp
static Logger* getInstance()
```

* Controls object creation
* Ensures only one instance is created

---

###  4. Lazy Initialization

```cpp
if (instance == nullptr)
```

* Object is created only when needed

---

##  Execution Flow

1. Program starts → `instance = nullptr`
2. First call → `getInstance()`

   * Creates new Logger object
   * Constructor runs → prints `"Logger initialized"`
3. First log → writes `"First message"` to file
4. Second call → `getInstance()`

   * Returns existing object (no new creation)
5. Second log → writes `"Second message"` to file
6. Compare pointers → both same → prints `1`

---

##  Output

### Console Output

```
Logger initialized
1
```

### File Output (`log.txt`)

```
First message
Second message
```

---

## ❓ Why NOT this output?

### ❌ Expectation:

```
Logger initialized
Logger initialized
First message
Second message
1
```

### 🚫 Why it does NOT happen:

* Constructor runs **only once** → Singleton ensures single object
* `log()` writes to **file**, not console
* Second call does NOT create a new object

---

##  Key Takeaways

* Singleton restricts object creation to **one instance**
* Constructor is **private** to prevent misuse
* Static instance ensures **shared access**
* Helps manage **shared resources safely**

---

##  Limitations

* Not thread-safe in this basic implementation
* Possible memory leak (no delete)
* Harder to test due to global state

---

##  Recommended Improvement (Modern C++)

Use **Meyers Singleton**:

```cpp
class Logger {
private:
    ofstream logFile;

    Logger() {
        logFile.open("log.txt", ios::app);
    }

public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(string msg) {
        logFile << msg << endl;
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};
```

✔ Thread-safe
✔ No memory leak
✔ Cleaner design

---

## 📌 Summary

| Feature        | Description      |
| -------------- | ---------------- |
| Instance count | One only         |
| Constructor    | Private          |
| Access         | Static method    |
| Initialization | Lazy             |
| Use case       | Shared resources |

---
