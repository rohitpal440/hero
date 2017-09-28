
/***
 * Problem:
 * Find nth largest element in a binary search tree
 ***/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* getNthLargestElement(Node* root, const int n) {
    int count = 0;
    function<Node*(Node*, const int, int&)> finder = [&](Node* root, const int n, int& count) -> Node* {
        if (!root)
        return nullptr;
        Node* nthLargestNode = finder(root->right, n, count);
        if (!nthLargestNode) {// not found in right sub-tree
            count++;
            if (count == n) {
                return root;
            }
                //search left sub-tree
            return finder(root->left, n, count);
        }
        return nthLargestNode;
    };
    return finder(root, n, count);
}

int main() {
    Node* leaf1 = new Node {4, nullptr, nullptr};
    Node* leaf2 = new Node {7, nullptr, nullptr};
    Node* leaf3 = new Node {14, nullptr, nullptr};
    Node* leaf4 = new Node {17, nullptr, nullptr};
    Node* intermediateNode1 = new Node {5, leaf1, leaf2};
    Node* intermediateNode2 = new Node {15, leaf3, leaf4};
    Node* root = new Node {10, intermediateNode1, intermediateNode2};
    auto result = getNthLargestElement(root, 5);
    if (result)
    cout << result->data << endl;
    else
    cout << "Null" << endl;
}
