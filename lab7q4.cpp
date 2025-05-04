#include <iostream>
#include <vector>
#include <string>

using namespace std;

string processString(const string& input) {
    vector<char> stack; // Using a vector to simulate stack behavior

    for (char ch : input) {
        if (ch == '+') {
            if (!stack.empty()) {
                stack.pop_back(); // Remove the last non-'+' character
            }
        } else {
            stack.push_back(ch); // Push the current character onto the stack
        }
    }

    // Build the result string from the vector
    string result;
    for (char ch : stack) {
        result += ch; // Append each character to the result
    }

    return result;
}

int main() {
    string input;
    cout << "Enter a string consisting of '+' symbols: ";
    cin >> input;

    string output = processString(input);
    cout << "Output: " << output << endl;

    return 0;
}