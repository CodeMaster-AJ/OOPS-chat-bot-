#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

// 🎨 ASCII Art for Welcome
void showWelcomeArt() {
    cout << R"(
============ Welcome to AJ ChatBot 💬 ============            
)";
    cout << "\n";
}

// 🌟 ChatBot Class
class AJchatbot {
private:
    string botName;

    // 🧠 Convert user input to lowercase
    string toLower(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    // ⏰ Get current time
    string getTime() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[10];
        sprintf(buffer, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
        return string(buffer);
    }

    // 📅 Get current date
    string getDate() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[12];
        sprintf(buffer, "%02d-%02d-%d", ltm->tm_mday, ltm->tm_mon + 1, 1900 + ltm->tm_year);
        return string(buffer);
    }

public:
    // 🛠️ Constructor
    AJchatbot(string name = "MegaBot") {
        botName = name;
        greetUser();
    }

    // 👋 Initial Greet
    void greetUser() {
        showWelcomeArt();
        cout << botName << ": Hello! I'm " << botName << " — your interactive C++ chatbot.\n";
        cout << botName << ": Type anything or ask for help by typing 'help'.\n\n";
    }

    // 💬 Main Response Logic
    void getResponse(string userInput) {
        string input = toLower(userInput);

        if (input == "hi" || input == "hello" || input == "hey") {
            cout << botName << ": Hi there! 😊 How can I help you?\n";
        } else if (input.find("name") != string::npos) {
            cout << botName << ": I'm " << botName << ", your friendly C++ chatbot.\n";
        } else if (input.find("time") != string::npos) {
            cout << botName << ": Current time is ⏰ " << getTime() << "\n";
        } else if (input.find("date") != string::npos) {
            cout << botName << ": Today's date is 📅 " << getDate() << "\n";
        } else if (input.find("how are you") != string::npos) {
            cout << botName << ": I'm fantastic! Just living the binary dream 😄\n";
        } else if (input == "help") {
            showHelp();
        } else if (input == "clear") {
            system("clear"); // use "cls" on Windows
            greetUser();
        } else if (input == "bye") {
            cout << botName << ": Are you sure you want to exit? (yes/no): ";
            string confirm;
            getline(cin, confirm);
            if (toLower(confirm) == "yes") {
                cout << botName << ": Alright, goodbye! 👋\n";
                exit(0);
            } else {
                cout << botName << ": Great! Let's continue chatting 😄\n";
            }
        } else {
            cout << botName << ": Hmm... I didn't get that. Type 'help' to see what I can do!\n";
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
        cout << " • help                   → Show this menu\n";
        cout << "----------------------------------\n\n";
    }
};

// 🧪 Main Program
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
