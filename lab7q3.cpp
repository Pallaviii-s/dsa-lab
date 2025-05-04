#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Queue class using a linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode; // If the queue is empty, both front and rear point to the new node
        } else {
            rear->next = newNode; // Link the new node at the end of the queue
            rear = newNode;       // Update the rear pointer
        }
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        cout << "Dequeued: " << front->data << endl;
        front = front->next; // Move front to the next node
        delete temp;         // Free the memory of the dequeued node

        if (front == nullptr) {
            rear = nullptr; // If the queue is now empty, update rear to nullptr
        }
    }

    // Peek operation
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// Function to display the menu
void displayMenu() {
    cout << "\nQueue Operations Menu:\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Peek\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Queue q;
    int choice, value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an integer to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}