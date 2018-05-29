#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

};

Node* getMinNode(Node* root) {
    Node* node = root;
    while(node->left != nullptr) {
        node =  node->left;
    }
    return node;
}

    // Duplicate keys are not allowed
Node* insert(int key, Node* root) {
    if (!root) {
        return new Node { key, nullptr, nullptr };
    }
    if (key < root->key) {
        root->left = insert(key, root->left);
    } else if (key > root->key) {
        root->right = insert(key, root->right);
    } else {
        printf("Duplicates keys are not allowed");
    }
    return root;
}

Node* deleteNode(int key, Node* root) {
    if (!root) return nullptr;
    if (key == root->key) {
        if (root->left && root->right) { // root has both children
                                         // Get min node from right subtree
            Node* minRightNode = getMinNode(root->right);
            root->key = minRightNode->key;
            root->right = deleteNode(minRightNode->key, root->right);
        } else {
            Node* tempNode = root->left ? root->left : root->right;
            delete root;
            return tempNode;
        }
    } else if (key < root->key) {
        root->left = deleteNode(key, root->left);
    } else {
        root->right = deleteNode(key, root->right);
    }
    return root;
}

void traverseTree(Node* root) {
    if (!root) {
            //        printf("nullptr\n");
        return;
    }
    Node* node = root;
    printf(" %d ", node->key);
    traverseTree(node->left);
    traverseTree(node->right);
}

int main() {
    Node* root = nullptr;
    root = insert(4, root);
    root = insert(7, root);
    root = insert(17, root);
    root = insert(10, root);
    root = insert(5, root);
    root = insert(14, root);
    root = insert(15, root);
    traverseTree(root);
    printf("\n");
    root = deleteNode(7, root);
    traverseTree(root);
    printf("\n");
}
