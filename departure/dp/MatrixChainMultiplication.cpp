/*
 Problem:
 Minimize the cost of multiplication of matrix
 */

#include <iostream>
#include <vector>
using namespace std;

void printParenthesis(int i, int j, const vector< vector<int> > &braces, const vector< pair<int,int> > &matrices) {
    if (i == j) {
        cout << "[" << matrices[i].first << " x " << matrices[i].second << "]";
    } else {
        cout << "(";
        printParenthesis(i, braces[i][j], braces, matrices);
        printParenthesis( braces[i][j] + 1, j, braces, matrices);
        cout << ")";
    }
}

int minCost(const vector< pair<int, int> > &matrices) {
    vector< vector<int> > cost(matrices.size(), vector<int>(matrices.size(), INT_MAX));
    vector< vector<int> > braces(matrices.size(), vector<int>(matrices.size(), INT_MAX));
    for (int i = 0; i < matrices.size(); i++) {
        cost[i][i] = 0;
    }
    for (int length = 2; length <= matrices.size(); length++) {
        for (int i = 0; i <= matrices.size() - length; i++) {
            int j = i + length - 1;
            for (int k = i; k < j ; k++) {
                int temp = cost[i][k] + cost[k+1][j] + matrices[i].first * matrices[k].second * matrices[j].second;
                if (temp < cost[i][j]) {
                    cost[i][j] = temp;
                    braces[i][j] = k; // split point of bracket
                }
            }
        }
    }
    printParenthesis(0, (int)matrices.size() - 1, braces, matrices);
    cout << endl;
    return cost[0][matrices.size() - 1];
}

int main() {
    vector< pair<int, int> > matrices = {
            //        {10, 20},// test case 1: 26000
            //        {20, 30},
            //        {30, 40},
            //        {40, 30}
        {40, 20}, // test case 2: 30000
        {20, 30},
        {30, 10},
        {10, 30}
            //        {2, 3}, // test case 3: 124
            //        {3, 6},
            //        {6, 4},
            //        {4, 5}
    };
    cout << minCost(matrices) << endl;
}

