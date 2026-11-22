

#ifndef BST_HPP
#define BST_HPP

#include <iostream>
using namespace std;

template <typename T>
class BST {
private:
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

    Node* insertNode(Node* node, T value) {
        if (node == NULL)
            return new Node(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else if (value > node->data)
            node->right = insertNode(node->right, value);

        return node;
    }

    bool searchNode(Node* node, T value) {
        if (node == NULL)
            return false;

        if (node->data == value)
            return true;

        if (value < node->data)
            return searchNode(node->left, value);

        return searchNode(node->right, value);
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node != NULL) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node != NULL) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    Node* findMin(Node* node) {
        while (node != NULL && node->left != NULL)
            node = node->left;

        return node;
    }

    Node* deleteNode(Node* node, T value) {
        if (node == NULL)
            return NULL;

        if (value < node->data)
            node->left = deleteNode(node->left, value);

        else if (value > node->data)
            node->right = deleteNode(node->right, value);

        else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }

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

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    void destroyTree(Node* node) {
        if (node != NULL) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        destroyTree(root);
        root = NULL;
    }

    void insert(T value) {
        root = insertNode(root, value);
    }

    bool search(T value) {
        return searchNode(root, value);
    }

    void remove(T value) {
        root = deleteNode(root, value);
    }

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

#endif
