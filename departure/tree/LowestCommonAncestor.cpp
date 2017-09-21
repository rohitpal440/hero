#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* getLowestCommonAncestor(Node *root, Node * const A, Node * const B) {
    if (!root || root == A || root == B)
        return root;
    Node *left = getLowestCommonAncestor(root->left, A, B);
    Node *right = getLowestCommonAncestor(root->right, A, B);
    if (left && right)
        return root;
    if (!left)
        return right;
    else
        return left;
}

int main() {
    Node *six = new Node {6, nullptr, nullptr};
    Node *seven = new Node {7, nullptr, nullptr};
    Node *four = new Node {4, nullptr, nullptr};
    Node *three = new Node {3, nullptr, nullptr};
    Node *five = new Node {5, six, seven};
    Node *two = new Node {2, four, five};
    Node *one = new Node {1, two, three};
    Node *root = one;
    Node *result = getLowestCommonAncestor(root, four, three);
    if (result) {
        cout << result->data << endl;
    } else {
        cout << "No Result found" << endl;
    }
}
