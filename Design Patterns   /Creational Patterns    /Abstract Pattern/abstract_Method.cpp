#include <iostream>
using namespace std;

// ================= Abstract Products =================
class Button {
public:
    virtual void render() = 0;
    virtual ~Button() {}
};

class TextBox {
public:
    virtual void render() = 0;
    virtual ~TextBox() {}
};

// ================= Concrete Products - Light Theme =================
class LightButton : public Button {
public:
    void render() override {
        cout << "Rendering Light Button" << endl;
    }
};

class LightTextBox : public TextBox {
public:
    void render() override {
        cout << "Rendering Light TextBox" << endl;
    }
};

// ================= Concrete Products - Dark Theme =================
class DarkButton : public Button {
public:
    void render() override {
        cout << "Rendering Dark Button" << endl;
    }
};

class DarkTextBox : public TextBox {
public:
    void render() override {
        cout << "Rendering Dark TextBox" << endl;
    }
};

// ================= Abstract Factory =================
class UIFactory {
public:
    virtual Button* createButton() = 0;
    virtual TextBox* createTextBox() = 0;
    virtual ~UIFactory() {}
};

// ================= Concrete Factories =================
class LightThemeFactory : public UIFactory {
public:
    Button* createButton() override {
        return new LightButton();
    }

    TextBox* createTextBox() override {
        return new LightTextBox();
    }
};

class DarkThemeFactory : public UIFactory {
public:
    Button* createButton() override {
        return new DarkButton();
    }

    TextBox* createTextBox() override {
        return new DarkTextBox();
    }
};

// ================= Client =================
class Application {
private:
    Button* button;
    TextBox* textbox;

public:
    Application(UIFactory* factory) {
        button = factory->createButton();
        textbox = factory->createTextBox();
    }

    void renderUI() {
        button->render();
        textbox->render();
    }

    ~Application() {
        delete button;
        delete textbox;
    }
};

// ================= Factory Selector =================
UIFactory* getFactory(string theme) {
    if (theme == "light")
        return new LightThemeFactory();
    else if (theme == "dark")
        return new DarkThemeFactory();
    else
        return nullptr;
}

// ================= Main =================
int main() {
    string theme;
    cout << "Enter theme (light/dark): ";
    cin >> theme;

    UIFactory* factory = getFactory(theme);

    if (!factory) {
        cout << "Invalid theme!" << endl;
        return 1;
    }

    Application app(factory);
    app.renderUI();

    delete factory;
    return 0;
}