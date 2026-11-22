
#include <iostream>
#include "BST.hpp"
using namespace std;

int main() {
    BST<int> tree;

    cout << "===== BINARY SEARCH TREE =====\n";

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

    cout << "\nSearching for 40: ";
    cout << (tree.search(40) ? "Found" : "Not Found") << endl;

    cout << "Searching for 90: ";
    cout << (tree.search(90) ? "Found" : "Not Found") << endl;

    cout << "\nDeleting 30...\n";
    tree.remove(30);

    cout << "Inorder Traversal after deletion: ";
    tree.inorderTraversal();

    cout << "\nProgram completed successfully.\n";

    return 0;
}
