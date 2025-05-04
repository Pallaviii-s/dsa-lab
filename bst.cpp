#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };
    
    Node* root;
    Node* createNode(int value);
    Node* insert(Node* root, int value);
    void preorder(Node* root);
    void inorder(Node* root);
    void postorder(Node* root);
    bool search(Node* root, int key);

public:
    BST() { root = nullptr; }
    ~BST() { root = nullptr; } // Destructor (For demonstration; memory deallocation needs explicit handling)

    void insert(int value) { root = insert(root, value); }
    void preorder() { preorder(root); cout << endl; }
    void inorder() { inorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
    bool search(int key) { return search(root, key); }
};

int main() {
    BST tree;
    int choice, value;

    do {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 3:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(value))
                    cout << "Value found in the tree." << endl;
                else
                    cout << "Value not found in the tree." << endl;
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);
    
    return 0;
}

BST::Node* BST::createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

BST::Node* BST::insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void BST::preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void BST::inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void BST::postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

bool BST::search(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == key) {
        return true;
    } else if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}
