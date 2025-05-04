#include <iostream>
#include <stack>
using namespace std;

class BST {
private:
    struct Node {
        char data;
        Node* left;
        Node* right;
    };
    
    Node* root;
    Node* createNode(char value);
    Node* insert(Node* root, char value);
    void preorder(Node* root);
    void inorder(Node* root);
    void postorder(Node* root);
    bool search(Node* root, char key);

public:
    BST() { root = nullptr; }
    ~BST() { root = nullptr; } // Destructor (For demonstration; memory deallocation needs explicit handling)

    void insert(char value) { root = insert(root, value); }
    void preorder() { preorder(root); cout << endl; }
    void inorder() { inorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
    bool search(char key) { return search(root, key); }
    void constructExpressionTree(const string& postfix);
};

int main() {
    BST tree;
    int choice;
    string postfix;
    char value;

    do {
        cout << "\nExpression Tree Operations:\n";
        cout << "1. Enter Postfix Expression\n2. Construct Expression Tree\n3. Preorder\n4. Inorder\n5. Postorder\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a valid postfix expression: ";
                cin >> postfix;
                break;
            case 2:
                tree.constructExpressionTree(postfix);
                cout << "Expression tree constructed successfully!" << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 4:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 5:
                cout << "Postorder Traversal: ";
                tree.postorder();
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

BST::Node* BST::createNode(char value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void BST::constructExpressionTree(const string& postfix) {
    stack<Node*> st;
    for (char ch : postfix) {
        Node* newNode = createNode(ch);
        if (isalnum(ch)) {
            st.push(newNode);
        } else {
            newNode->right = st.top(); st.pop();
            newNode->left = st.top(); st.pop();
            st.push(newNode);
        }
    }
    root = st.top();
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

bool BST::search(Node* root, char key) {
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
