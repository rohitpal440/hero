
/***
 * Problem:
 * Find nth diagonal sum in a tree
 ***/

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

int getNthDiagonalSum(Node* root, const int nthDiagonal) {
    unordered_map<int, int> map;
    function<void(Node*, const int, unordered_map<int, int>&)> calculateDiagonalSum = [&](Node* root, const int currentDiagonal, unordered_map<int, int>& map) {
        if (!root)
        return;
        calculateDiagonalSum(root->left, currentDiagonal + 1, map);
        int previousSum = 0;
        if (map.find(currentDiagonal) != map.end()) {
            previousSum = map[currentDiagonal];
        }
        map[currentDiagonal] = previousSum + root->data;
        calculateDiagonalSum(root->right, currentDiagonal, map);
    };
    calculateDiagonalSum(root, 1, map);
    if (map.find(nthDiagonal) != map.end()) {
        return map[nthDiagonal];
    }
    return 0;
}

int main() {
    Node* leaf1 = new Node {4, nullptr, nullptr};
    Node* leaf2 = new Node {7, nullptr, nullptr};
    Node* leaf3 = new Node {14, nullptr, nullptr};
    Node* leaf4 = new Node {17, nullptr, nullptr};
    Node* intermediateNode1 = new Node {5, leaf1, leaf2};
    Node* intermediateNode2 = new Node {15, leaf3, leaf4};
    Node* root = new Node {10, intermediateNode1, intermediateNode2};
    cout << getNthDiagonalSum(root, 1) << endl;
}
