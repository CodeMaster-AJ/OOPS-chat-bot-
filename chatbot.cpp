#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

// 🎨 ASCII Welcome Art
void showWelcomeArt() {
    cout << R"(
============ Welcome to AJ ChatBot 💬 ============            
)";
    cout << "\n";
}

// 🔵 Base Class for Reusability – [INHERITANCE + ABSTRACTION]
class BotBase {
protected:
    string botName;

    string toLower(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    string getTime() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[10];
        sprintf(buffer, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
        return string(buffer);
    }

    string getDate() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[12];
        sprintf(buffer, "%02d-%02d-%d", ltm->tm_mday, ltm->tm_mon + 1, 1900 + ltm->tm_year);
        return string(buffer);
    }

public:
    virtual void greetUser() = 0; // Pure Virtual [ABSTRACTION + POLYMORPHISM]
    virtual void getResponse(string input) = 0;
    virtual ~BotBase() {} // Virtual Destructor
};

// 🟢 Derived Class – [INHERITANCE + ENCAPSULATION]
class AJchatbot : public BotBase {
private:
    static int chatCount; // [STATIC MEMBER]

public:
    // 🛠️ Constructor
    AJchatbot(string name = "MegaBot") {
        botName = name;
        greetUser();
    }

    // 🧹 Destructor
    ~AJchatbot() {
        cout << botName << ": Shutting down... Bye! 👋\n";
    }

    // 👋 Greeting Message – [POLYMORPHISM]
    void greetUser() override {
        showWelcomeArt();
        cout << botName << ": Hello! I'm " << botName << ", your interactive OOP C++ ChatBot.\n";
        cout << botName << ": Type anything or ask for help using 'help'.\n\n";
    }

    // 🧠 Function Overloading Example
    void info() {
        cout << botName << ": I'm an AI bot using OOP concepts in C++!\n";
    }

    void info(string topic) {
        cout << botName << ": You asked about '" << topic << "'. Here's what I can tell...\n";
    }

    // 💬 Handle Responses
    void getResponse(string userInput) override {
        chatCount++; // increment chat count
        string input = toLower(userInput);

        if (input == "hi" || input == "hello" || input == "hey") {
            cout << botName << ": Hi there! 😊 How can I help you?\n";
        } else if (input.find("name") != string::npos) {
            cout << botName << ": I'm " << botName << ", your friendly chatbot.\n";
        } else if (input.find("time") != string::npos) {
            cout << botName << ": Current time is ⏰ " << getTime() << "\n";
        } else if (input.find("date") != string::npos) {
            cout << botName << ": Today's date is 📅 " << getDate() << "\n";
        } else if (input.find("how are you") != string::npos) {
            cout << botName << ": I'm doing great! Living the binary dream 😄\n";
        } else if (input == "help") {
            showHelp();
        } else if (input == "info") {
            info(); // overloaded function
        } else if (input.find("info about") != string::npos) {
            info(input); // overloaded function
        } else if (input == "clear") {
            system("clear"); // use "cls" on Windows
            greetUser();
        } else if (input == "bye") {
            cout << botName << ": Are you sure you want to exit? (yes/no): ";
            string confirm;
            getline(cin, confirm);
            if (toLower(confirm) == "yes") {
                cout << botName << ": Goodbye! You had " << chatCount << " interactions. 👋\n";
                exit(0);
            } else {
                cout << botName << ": Awesome! Let's keep chatting 😄\n";
            }
        } else {
            cout << botName << ": Sorry, I didn't understand that. Type 'help' to know more.\n";
        }
    }

    // 📖 Help Menu
    void showHelp() {
        cout << "\n📚 " << botName << " Help Menu:\n";
        cout << "----------------------------------\n";
        cout << " • hi / hello / hey       → Greetings\n";
        cout << " • name                   → Know bot's name\n";
        cout << " • how are you            → Friendly reply\n";
        cout << " • time                   → Current time\n";
        cout << " • date                   → Today's date\n";
        cout << " • clear                  → Clear the screen\n";
        cout << " • bye                    → Exit the bot\n";
        cout << " • info / info about X    → Bot info\n";
        cout << " • help                   → Show this menu\n";
        cout << "----------------------------------\n\n";
    }
};

// 🧮 Initialize static member
int AJchatbot::chatCount = 0;

// 🔁 Main Program
int main() {
    AJchatbot bot("AJ");
    string userInput;

    while (true) {
        cout << "You: ";
        getline(cin, userInput);
        bot.getResponse(userInput);
    }

    return 0;
}
