#include <iostream>
#include <string>
#include <map>

using namespace std;

// Product
class HttpRequest {
private:
    string url;
    string method;
    map<string, string> headers;
    string body;

public:
    // Constructor is private - only Builder can create
    HttpRequest(string url, string method,
                map<string, string> headers,
                string body)
        : url(url), method(method), headers(headers), body(body) {}

    void print() {
        cout << "HTTP Request:\n";
        cout << "URL: " << url << endl;
        cout << "Method: " << method << endl;

        cout << "Headers:\n";
        for (auto &h : headers) {
            cout << "  " << h.first << ": " << h.second << endl;
        }

        cout << "Body: " << body << endl;
    }

    // Builder class
    class Builder {
    private:
        string url;
        string method = "GET"; // default
        map<string, string> headers;
        string body = "";

    public:
        // Required parameter
        Builder(string url) {
            this->url = url;
        }

        Builder& setMethod(string method) {
            this->method = method;
            return *this;
        }

        Builder& addHeader(string key, string value) {
            headers[key] = value;
            return *this;
        }

        Builder& setBody(string body) {
            this->body = body;
            return *this;
        }

        HttpRequest build() {
            return HttpRequest(url, method, headers, body);
        }
    };
};

// Main function
int main() {
    HttpRequest request = HttpRequest::Builder("https://api.example.com/users")
                              .setMethod("POST")
                              .addHeader("Content-Type", "application/json")
                              .addHeader("Authorization", "Bearer token123")
                              .setBody("{\"name\":\"John\"}")
                              .build();

    request.print();

    return 0;
}