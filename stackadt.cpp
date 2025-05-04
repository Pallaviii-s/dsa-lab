//Program to implement a Stack ADT using static array
#include <iostream>
using namespace std;

#define SIZE 5

class Stack {
private:
    int top;
    char arr[SIZE];  

public:
    Stack() {
        top = -1;
    }
    void push(char);
    void pop();
    void peek();
};

int main() {
    char value;
    int choice;
    Stack stack1;

    do {
        cout << "\nMENU\n1. Push\n2. Pop\n3. Peek\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to be pushed in stack: ";
                cin >> value;
                stack1.push(value);
                break;
            case 2:
                stack1.pop();
                break;
            case 3:
                stack1.peek();
                break;
            case 4:
                cout << "Exiting operation...\n";
                break;
            default:
                cout << "Invalid input.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

// Push a character into the stack.
void Stack::push(char value) {
    if (top == SIZE - 1) {
        cout << "Stack overflow\n";
        return;
    }
    arr[++top] = value;
}


// Pop the top character from the stack
void Stack::pop() {
    if (top == -1) {
        cout << "Stack underflow\n";
        return;
    }
    cout << "Popped element: " << arr[top--] << endl;
}

// Return the top character of the stack
void Stack::peek() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "The top element is: " << arr[top] << endl;
}
