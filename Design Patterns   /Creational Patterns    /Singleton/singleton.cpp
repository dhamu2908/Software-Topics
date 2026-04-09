#include <iostream>
#include <fstream>
using namespace std;

class Logger {
private:
    static Logger* instance;
    ofstream logFile;

    // Private constructor
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

    // Destructor to close file
    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
};

// Initialize static member
Logger* Logger::instance = nullptr;

int main() {
    Logger* logger1 = Logger::getInstance();
    logger1->log("First message");

    Logger* logger2 = Logger::getInstance();
    logger2->log("Second message");

    // Check same instance
    cout << (logger1 == logger2) << endl; // 1 (true)

    return 0;
}