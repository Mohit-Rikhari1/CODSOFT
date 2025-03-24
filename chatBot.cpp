#include <iostream>
#include <string>
using namespace std;

// Function to get the chatbot's response
string getResponse(string userInput) {
    // Define rules for responses
    if (userInput == "hello") {
        return "Hi there! How can I assist you today?";
    } else if (userInput == "how are you") {
        return "I'm just a chatbot, but I'm doing great! How about you?";
    } else if (userInput == "what is your name") {
        return "I'm Chatbot! Here to help you.";
    } else if (userInput == "bye") {
        return "Goodbye! Have a great day!";
    } else {
        return "I'm sorry, I don't understand that. Could you rephrase?";
    }
}

int main() {
    string userInput;

    cout << "Chatbot: Hello! Type your message below." << endl;

    while (true) {
        // Get user input
        cout << "You: ";
        getline(cin, userInput);

        // Exit loop if the user says "bye"
        if (userInput == "bye") {
            cout << "Chatbot: " << getResponse(userInput) << endl;
            break;
        }

        // Display the chatbot's response
        cout << "Chatbot: " << getResponse(userInput) << endl;
    }

    return 0;
}
