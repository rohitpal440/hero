#include <iostream>
#include <unordered_map>
using namespace std;

class DisjointSet {
private:
    struct Node {
        int data;
        int rank;
        Node* parent;
    };
    unordered_map<int, Node*> setMap;

    Node* findSet(Node* node) {
        if (node->parent != node) {
            node->parent = findSet(node->parent);
        }
        return node->parent;
    }
public:
    void makeSet(int data) {
        if (setMap.find(data) == setMap.end()) {
            auto node = new Node{data, 0, nullptr};
            node->parent = node;
            setMap[data] = node;
        }
    }

    pair<bool, int> findSet(int data) {
        if (setMap.find(data) != setMap.end()) {
            auto node = findSet(setMap[data]);
            return make_pair(true, node->data);
        }
        return make_pair(false, INT_MAX);
    }

    pair<bool, int> unionSet(int set1, int set2) {
        if (setMap.find(set1) == setMap.end() || setMap.find(set2) == setMap.end()) {
            return make_pair(false, INT_MIN);
        }
        auto node1 = findSet(setMap[set1]);
        auto node2 = findSet(setMap[set2]);
        if (node1 == node2) return make_pair(true, node1->data);
        Node* root;
        if (node1->rank < node2->rank) {
            node1->parent = node2;
            root = node2;
        } else {
            node2->parent = node1;
            root = node1;
        }
        root->rank++;
        return make_pair(true, root->data);
    }
};


int main() {
    DisjointSet mySet;
    for (int i = 0; i < 10; i++)
        mySet.makeSet(i);
    cout << mySet.findSet(5).second << endl;
    cout << "Union of 5 and 8 : " << mySet.unionSet(5, 8).second << endl;
    cout << "Union of 1 and 2 : " << mySet.unionSet(1, 2).second << endl;
    cout << "Union of 2 and 8 : " << mySet.unionSet(2, 8).second << endl;
    cout << mySet.findSet(5).second << endl;
    cout << mySet.findSet(1).second << endl;
    cout << mySet.findSet(2).second << endl;
    cout << mySet.findSet(8).second << endl;
    cout << "Union of 18 and 19 : " << mySet.unionSet(18, 19).second << endl;
}
