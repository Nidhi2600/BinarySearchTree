
#include <iostream>
using namespace std;

// Template-based Binary Search Tree
template <typename T>
class BST {
private:
    // Node structure
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T value) {
            data = value;
            left = NULL;
            right = NULL;
        }
    };

    Node* root;

    // Insert node recursively
    Node* insertNode(Node* node, T value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    // Search recursively
    bool searchNode(Node* node, T value) {
        if (node == NULL) {
            return false;
        }

        if (node->data == value) {
            return true;
        }

        if (value < node->data) {
            return searchNode(node->left, value);
        }

        return searchNode(node->right, value);
    }

    // Inorder traversal
    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    // Preorder traversal
    void preorder(Node* node) {
        if (node != NULL) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    // Postorder traversal
    void postorder(Node* node) {
        if (node != NULL) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    // Find minimum value node
    Node* findMin(Node* node) {
        while (node != NULL && node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    // Delete node recursively
    Node* deleteNode(Node* node, T value) {
        if (node == NULL) {
            return NULL;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        }
        else {
            // Node with no child
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }

            // Node with one child
            else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    // Free memory recursively
    void destroyTree(Node* node) {
        if (node != NULL) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    // Constructor
    BST() {
        root = NULL;
    }

    // Destructor
    ~BST() {
        destroyTree(root);
        root = NULL;
    }

    // Public insert
    void insert(T value) {
        root = insertNode(root, value);
    }

    // Public search
    bool search(T value) {
        return searchNode(root, value);
    }

    // Public delete
    void remove(T value) {
        root = deleteNode(root, value);
    }

    // Public traversals
    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }

    void preorderTraversal() {
        preorder(root);
        cout << endl;
    }

    void postorderTraversal() {
        postorder(root);
        cout << endl;
    }
};

// Main function
int main() {
    BST<int> tree;

    cout << "===== BINARY SEARCH TREE =====\n";

    // Insert values
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "\nInorder Traversal: ";
    tree.inorderTraversal();

    cout << "Preorder Traversal: ";
    tree.preorderTraversal();

    cout << "Postorder Traversal: ";
    tree.postorderTraversal();

    // Search
    cout << "\nSearching for 40: ";
    if (tree.search(40)) {
        cout << "Found\n";
    }
    else {
        cout << "Not Found\n";
    }

    cout << "Searching for 90: ";
    if (tree.search(90)) {
        cout << "Found\n";
    }
    else {
        cout << "Not Found\n";
    }

    // Delete
    cout << "\nDeleting 30...\n";
    tree.remove(30);

    cout << "Inorder Traversal after deletion: ";
    tree.inorderTraversal();

    cout << "\nProgram completed successfully.\n";

    return 0;
}
