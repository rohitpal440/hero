#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class DisjointSet {
private:
    struct Node {
        char data;
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
    void makeSet(char data) {
        if (setMap.find(data) == setMap.end()) {
            auto node = new Node{data, 0, nullptr};
            node->parent = node;
            setMap[data] = node;
        }
    }

    pair<bool, char> findSet(char data) {
        if (setMap.find(data) != setMap.end()) {
            auto node = findSet(setMap[data]);
            return make_pair(true, node->data);
        }
        return make_pair(false, 0);
    }

    pair<bool, char> unionSet(char set1, char set2) {
        if (setMap.find(set1) == setMap.end() || setMap.find(set2) == setMap.end()) {
            return make_pair(false, 0);
        }
        auto node1 = findSet(setMap[set1]);
        auto node2 = findSet(setMap[set2]);
        Node* root;
        if (node1 == node2) {
            cout << "Rank: " << node1->rank << endl;
            return make_pair(true, node1->data);
        }
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

struct Edge {
    char srcNode;
    char dstNode;
    int weight;
    bool operator<(const Edge &otherEdge) const {
        return this->weight > otherEdge.weight; // for min heap
    }
};

vector<Edge> minSpanningTree(const vector<char> &nodes, const vector<Edge> &edges) {
    DisjointSet mySet;
    priority_queue< Edge > q(edges.begin(), edges.end());
    vector<Edge> result;
    for (auto ch: nodes )
        mySet.makeSet(ch);
    while (!q.empty()) {
        auto edge = q.top();
        q.pop();
        if (mySet.findSet(edge.srcNode) != mySet.findSet(edge.dstNode)) {
            result.push_back(edge);
            mySet.unionSet(edge.srcNode, edge.dstNode);
        }
    }
    return result;
}

void printEdges(const vector<Edge> &array) {
    for (auto edge: array)
        cout << edge.srcNode << edge.dstNode << " ";
    cout << endl;
}

int main() {
    vector<char> nodes = {'A', 'B', 'C', 'D', 'E', 'F'};
    vector<Edge> edges = {
        Edge{'A', 'B', 3},
        Edge{'A', 'D', 1},
        Edge{'B', 'C', 1},
        Edge{'B', 'D', 3},
        Edge{'C', 'D', 1},
        Edge{'C', 'E', 5},
        Edge{'C', 'F', 4},
        Edge{'D', 'E', 6},
        Edge{'E', 'F', 2},
    };
    printEdges(minSpanningTree(nodes, edges));
    return 0;
}

