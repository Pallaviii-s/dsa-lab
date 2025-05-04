#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    static const int capacity = 5;
    int queue[capacity];

public:
    Queue() : front(0), rear(-1), size(0) {}

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        queue[rear] = value;
        size++;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << queue[front] << endl;
        front = (front + 1) % capacity; // Circular increment
        size--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return;
        }
        cout << "Front element: " << queue[front] << endl;
    }
};

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