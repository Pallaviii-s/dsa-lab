#include <iostream>
#include <cstdlib>  // For malloc and free
using namespace std;

class List {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:
    List() : head(nullptr) {}  // Constructor initializes empty list

    void insertBeginning(int value);
    void insertEnd(int value);
    void insertPosition(int pos, int value);
    void deleteBeginning();
    void deleteEnd();
    void deletePosition(int pos);
    int search(int value);
    void display();
    void displayReverse();
    void reverseList();
    void reversePrintHelper(Node* node);  // Helper function for reverse display

    ~List();  // Destructor to free memory
};

int main() {
    List list;
    int choice, value, pos;

    do {
        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Display Reverse\n10. Reverse List\n11. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertEnd(value);
            break;
        case 3:
            cout << "Enter position and value: ";
            cin >> pos >> value;
            list.insertPosition(pos, value);
            break;
        case 4:
            list.deleteBeginning();
            break;
        case 5:
            list.deleteEnd();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            list.deletePosition(pos);
            break;
        case 7:
            cout << "Enter value: ";
            cin >> value;
            pos = list.search(value);
            if (pos != -1)
                cout << "Found at position " << pos << endl;
            else
                cout << "Not found" << endl;
            break;
        case 8:
            list.display();
            break;
        case 9:
            list.displayReverse();
            break;
        case 10:
            list.reverseList();
            cout << "List reversed successfully!\n";
            break;
        case 11:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 11);
    
    return 0;
}

// Insert at the beginning
void List::insertBeginning(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        cout << "Memory allocation failed!\n";
        return;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at the end
void List::insertEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        cout << "Memory allocation failed!\n";
        return;
    }
    newNode->data = value;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Insert at a given position (1-based)
void List::insertPosition(int pos, int value) {
    if (pos < 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1) {
        insertBeginning(value);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        cout << "Memory allocation failed!\n";
        return;
    }
    newNode->data = value;
    newNode->next = nullptr;

    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
    if (!temp) {
        cout << "Position out of range!" << endl;
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from the beginning
void List::deleteBeginning() {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete from the end
void List::deleteEnd() {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }
    if (!head->next) {
        free(head);
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    free(temp->next);
    temp->next = nullptr;
}

// Delete from a specific position (1-based)
void List::deletePosition(int pos) {
    if (!head || pos < 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1) {
        deleteBeginning();
        return;
    }
    Node* temp = head;
    for (int i = 1; temp->next && i < pos - 1; i++) temp = temp->next;
    if (!temp->next) {
        cout << "Position out of range!" << endl;
        return;
    }
    Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

// Search for a value and return position (1-based)
int List::search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == value) return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

// Display list in normal order
void List::display() {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }
    cout << "List: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Display list in reverse order (without modifying list)
void List::displayReverse() {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }
    cout << "Reverse: ";
    reversePrintHelper(head);
    cout << endl;
}

// Helper function to print in reverse (recursive)
void List::reversePrintHelper(Node* node) {
    if (!node) return;
    reversePrintHelper(node->next);
    cout << node->data << " ";
}

// Reverse the linked list (modifies structure)
void List::reverseList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Destructor to free memory
List::~List() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
