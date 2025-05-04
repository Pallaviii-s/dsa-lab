#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Tree class
class BinaryTree {
private:
    Node* root;

public:
    BinaryTree(); // Constructor
    void insert(char value); // Insert function prototype
    void preorder(); // Preorder traversal prototype
    void inorder(); // Inorder traversal prototype
    void postorder(); // Postorder traversal prototype
    bool search(char value); // Search function prototype

private:
    Node* insert(Node* node, char value); // Private insert helper
    void preorder(Node* node); // Private preorder helper
    void inorder(Node* node); // Private inorder helper
    void postorder(Node* node); // Private postorder helper
    bool search(Node* node, char value); // Private search helper
};

// Constructor
BinaryTree::BinaryTree() : root(nullptr) {}

// Private insert helper
Node* BinaryTree::insert(Node* node, char value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    return node;
}

// Public insert function
void BinaryTree::insert(char value) {
    root = insert(root, value);
}

// Private preorder helper
void BinaryTree::preorder(Node* node) {
    if (node) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

// Public preorder function
void BinaryTree::preorder() {
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
}

// Private inorder helper
void BinaryTree::inorder(Node* node) {
    if (node) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

// Public inorder function
void BinaryTree::inorder() {
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
}

// Private postorder helper
void BinaryTree::postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

// Public postorder function
void BinaryTree::postorder() {
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
}

// Private search helper
bool BinaryTree::search(Node* node, char value) {
    if (node == nullptr) {
        return false;
    }
    if (node->data == value) {
        return true;
    }
    if (value < node->data) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

// Public search function
bool BinaryTree::search(char value) {
    return search(root, value);
}

// Function to display the menu
void displayMenu() {
    cout << "\nBinary Tree Operations Menu:\n";
    cout << "1. Insert\n";
    cout << "2. Preorder Traversal\n";
    cout << "3. Inorder Traversal\n";
    cout << "4. Postorder Traversal\n";
    cout << "5. Search\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    BinaryTree tree;
    int choice;
    char value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a character to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                tree.preorder();
                break;
            case 3:
                tree.inorder();
                break;
            case 4:
                tree.postorder();
                break;
            case 5:
                cout << "Enter a character to search: ";
                cin >> value;
                if (tree.search(value)) {
                    cout << value << " found in the tree." << endl;
                } else {
                    cout << value << " not found in the tree." << endl;
                }
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
