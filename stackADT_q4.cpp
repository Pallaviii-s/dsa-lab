//Balanced Parentheses Problem using Stack ADT
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }

    void push(char data);
    char pop();
    char peek();
    bool isEmpty();
};

bool isBalanced(string str) ;




int main() {
    int choice;
    string expression;
    
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter the Parenthesis Expression: ";
            getline(cin, expression);
            if (isBalanced(expression)) {
                cout << "The Parentheses are Balanced." << endl;
            } else {
                cout << "The Parentheses are Not Balanced." << endl;
            }
            break;
        case 2:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (choice != 2);

    return 0;
}


//pushes an element into the stack
void Stack::push(char data) {
    Node* newNode = new Node(data);
    newNode->next = top;
    top = newNode;
}

//deletes the topmost element from the stack
char Stack::pop() {
    if (isEmpty()) {
        return -1;
    }
    Node* temp = top;
    char popped = top->data;
    top = top->next;
    delete temp;
    return popped;
}

//returns the topmost element from the stack
char Stack::peek() {
    if (isEmpty()) {
        return -1;
    }
    return top->data;
}

//to check if the stack is empty
bool Stack::isEmpty() {
    return top == nullptr;
}

//checks if the stack is balanced
bool isBalanced(string str) {
    Stack s;
    for (char ch : str) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.isEmpty()) {
                return false;
            }
            s.pop();
        }
    }
    return s.isEmpty();
}

