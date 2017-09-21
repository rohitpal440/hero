#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* getBalancedBST(const vector<int> & array, const int left, const int right) {
    if (left <=right) {
        int mid = left + (right - left) / 2;
        return new Node {array[mid], getBalancedBST(array, left, mid - 1), getBalancedBST(array, mid + 1, right)};
    }
    return nullptr;
}

void inorderTraverseBST(Node *root) {
    if (!root)
        return;
    inorderTraverseBST(root->left);
    cout << root->data << " ";
    inorderTraverseBST(root->right);
}

int main() {
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    inorderTraverseBST(getBalancedBST(array, 0, 8));
}
