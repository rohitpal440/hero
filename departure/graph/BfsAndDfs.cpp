// BFS And DFS Algorithm

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    int numberOfNodes;
    vector< list<int> > adjacencyList;
    
    void dfsHelper(int startNode, vector<bool> &visited, list<int> &traversalList) {
        visited[startNode] = true;
        traversalList.push_back(startNode);
        for ( auto it = adjacencyList[startNode].begin(); it != adjacencyList[startNode].end(); ++it)
            if (!visited[*it])
                dfsHelper(*it, visited, traversalList);
    }
    
    void printPath(const list<int> &list) {
        for (auto element: list)
            cout << element << " ";
        cout << endl;
    }
public:
    Graph(int nodeCounts) {
        this->numberOfNodes = nodeCounts;
        adjacencyList.resize(nodeCounts);
    }
    
    void addEdge(int src, int dest) {
        adjacencyList[src].push_back(dest);
        //        adjacencyList[dest].push_back(src); //uncomment for undirected graph
    }
    
    list<int> bfs(int start) {
        vector<bool> visited(numberOfNodes, false);
        list<int> traversalList;
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            auto element = q.front();
            traversalList.push_back(element);
            q.pop();
            for ( auto it = adjacencyList[element].begin(); it != adjacencyList[element].end(); ++it) {
                if (!visited[*it]) {
                    q.push(*it);
                    visited[*it] = true;
                }
            }
        }
        printPath(traversalList);
        return traversalList;
    }
    
    list<int> dfs(int start, bool recursive = false) {
        vector<bool> visited(numberOfNodes, false);
        list<int> traversalList;
        if (recursive) {
            dfsHelper(start, visited, traversalList);
        } else {
            stack <int> stk;
            stk.push(start);
            while(!stk.empty()) {
                auto element = stk.top();
                stk.pop();
                if (!visited[element]) {
                    visited[element] = true;
                    traversalList.push_back(element);
                }
                // using rbegin and rend iterator for consitency with recursive version
                for ( auto it = adjacencyList[element].rbegin(); it != adjacencyList[element].rend(); ++it)
                    if (!visited[*it])
                        stk.push(*it);
                
            }
        }
        printPath(traversalList);
        return traversalList;
    }
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);
    graph.bfs(1);
    graph.dfs(2);
    return 0;
}
