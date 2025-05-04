//Expression Conversion and Evaluation using Stack ADT

#include<iostream>
#include<stack>
#include<cctype>
#include<string>
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

int precedence(char op);
string infixToPostfix(string infix);
int evaluatePostfix(string postfix);



int evaluatePostfix(string postfix) {
    Stack s;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.pop();
}

int main() {
    int choice;
    string infix;
    string postfix;

    do {
        cout << "\nMenu: " << endl;
        cout << "1. Get Infix" << endl;
        cout << "2. Convert Infix" << endl;
        cout << "3. Evaluate Postfix" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter the Infix Expression: ";
            getline(cin, infix);
            break;
        case 2:
            postfix = infixToPostfix(infix);
            cout << "Postfix Expression: " << postfix << endl;
            break;
        case 3:
            cout << "Postfix Evaluation Result: " << evaluatePostfix(postfix) << endl;
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}

//pushes element to into the stack
void Stack::push(char data) {
    Node* newNode = new Node(data);
    newNode->next = top;
    top = newNode;
}

//deletes the topmost element
char Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    Node* temp = top;
    char popped = top->data;
    top = top->next;
    delete temp;
    return popped;
}


//returns the top most element
char Stack::peek() {
    if (isEmpty()) {
        return -1;
    }
    return top->data;
}


bool Stack::isEmpty() {
    return top == nullptr;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// infix to postfix
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); 
        } else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.isEmpty()) {
        postfix += s.pop();
    }
    return postfix;
}

//evaluating postfix
int evaluatePostfix(string postfix) {
    Stack s;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.pop();
}
