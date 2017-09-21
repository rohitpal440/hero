#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

int getMinimumDepth(Node *root) {
    if (!root)
        return 0;
    if (root->left && root->right)
        return 1 + min(getMinimumDepth(root->left), getMinimumDepth(root->right));
    else if (!root->left)
        return 1 + getMinimumDepth(root->right);
    else
        return 1 + getMinimumDepth(root->left);
}

int getMaxDepth(Node *root) {
    if (!root)
        return 0;
    if (root->left && root->right)
        return 1 + max(getMaxDepth(root->left), getMaxDepth(root->right));
    else if (!root->left)
        return 1 + getMaxDepth(root->right);
    else
        return 1 + getMaxDepth(root->left);
}

int main() {
    Node *ten = new Node {10, nullptr, nullptr};
    Node *seven = new Node {7, nullptr, ten};
    Node *six = new Node {6, nullptr, nullptr};
    Node *three = new Node {3, six, seven};
    Node *nine = new Node {9, nullptr, nullptr};
    Node *five = new Node {5, nullptr, nine};
    Node *eleven = new Node {11, nullptr, nullptr};
    Node *eight = new Node {8, eleven, nullptr};
    Node *four = new Node {4, nullptr, eight};
    Node *two = new Node {2, four, five};
    Node *one = new Node {1, two, three};
    Node *root = one;
    cout << getMinimumDepth(root) << endl; // 3
    cout << getMaxDepth(root) << endl; // 5
}
