/***
 * Problem:
 * If two nodes of a binary search tree (BST) are swapped by
 * mistake. Restore the BST structure without changing positions
 * of nodes which are correctly placed.
 ***/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class BSTRestorer {
    Node* firstMisplacedNode = nullptr;
    Node* secondMisplacedNode = nullptr;
    Node* previousNode = nullptr;

    void findMisplacedNodes(Node *root) {
        if (!root)
        return;
        findMisplacedNodes(root->left);
        if (previousNode && previousNode -> data > root -> data) {
            if (!firstMisplacedNode) {
                firstMisplacedNode = previousNode;
            }
            secondMisplacedNode = root;
        }
        previousNode = root;
        findMisplacedNodes(root->right);
    }

public:
    void restore(Node* root) {
        findMisplacedNodes(root);
        swap(firstMisplacedNode->data, secondMisplacedNode->data);
    }
};

void inOrderTraversal(Node* root) {
    if (!root)
    return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    Node* leaf1 = new Node {4, nullptr, nullptr};
    Node* leaf2 = new Node {7, nullptr, nullptr};
    Node* leaf3 = new Node {15, nullptr, nullptr};
    Node* leaf4 = new Node {17, nullptr, nullptr};
    Node* misplacedNode1 = new Node {5, leaf1, leaf2};
    Node* misplacedNode2 = new Node {14, leaf3, leaf4};
    Node* root = new Node {10, misplacedNode1, misplacedNode2};
    Node* temp = root;
    BSTRestorer bstRestorer = BSTRestorer();
    inOrderTraversal(temp);
    cout << endl;
    bstRestorer.restore(temp);
    inOrderTraversal(temp);
    cout << endl;
}
