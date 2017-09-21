
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};


void levelOrderTraversal(Node *root) {
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    int level = 0;
    cout << "Level " << level << " : ";
    while(!q.empty()) {
        auto element = q.front();
        q.pop();
        if (element) {
            cout << element->data << " ";
            if (element->left)
                q.push(element->left);
            if (element->right)
                q.push(element->right);
        } else if (!q.empty()) {
            level++;
            cout << endl;
            cout << "Level " << level << " : ";
            q.push(nullptr);
        }
    }
    cout << endl;
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
    levelOrderTraversal(root);
}
