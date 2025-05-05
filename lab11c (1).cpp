////Menu Driven Program to implement HashADT with Separate Chaining
#include <stdio.h>
#include <stdlib.h>
#include<cstdio>
#define TABLE_SIZE 10
class chain{
    private:
    struct Node {
        int key;
        struct Node* next;
    };
    Node* hashTable[TABLE_SIZE];
    int hash(int key) {
        return key % TABLE_SIZE;
    }
    public:
    chain() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            hashTable[i] = nullptr;
        }
    }
    // chain();               
    // ~chain(); 
    void insert(int);
    void remove(int);
    void search(int);
    void display();
    void cleanup();


};




// Insert key into the hash table
void chain::insert(int key) {
    int index = hash(key);

    // Check for duplicates
    struct Node* current = hashTable[index];
    while (current != NULL) {
        if (current->key == key) {
            printf("Key %d already exists at index %d.\n", key, index);
            return;
        }
        current = current->next;
    }

    // Create new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    printf("Key %d inserted at index %d.\n", key, index);
}

// Delete key from the hash table
void chain::remove(int key) {
    int index = hash(key);
    struct Node* current = hashTable[index];
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL)
                hashTable[index] = current->next;
            else
                prev->next = current->next;

            free(current);
            printf("Key %d deleted from index %d.\n", key, index);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Key %d not found in the hash table.\n", key);
}

// Search for a key in the hash table
void chain::search(int key) {
    int index = hash(key);
    struct Node* current = hashTable[index];

    while (current != NULL) {
        if (current->key == key) {
            printf("Key %d found at index %d.\n", key, index);
            return;
        }
        current = current->next;
    }

    printf("Key %d not found in the hash table.\n", key);
}

// Display the hash table
void chain::display() {
    printf("\nHash Table (Separate Chaining):\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        struct Node* current = hashTable[i];
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Free memory
void chain::cleanup() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* current = hashTable[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

// Main menu-driven function
int main() {
    int choice, key;
    chain hashTable;

    
    do {
        printf("\n--- Hash Table Menu (Separate Chaining in C) ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                hashTable.insert(key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                hashTable.remove(key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                hashTable.search(key);
                break;
            case 4:
                hashTable.display();
                break;
            case 5:
                hashTable.cleanup();
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
