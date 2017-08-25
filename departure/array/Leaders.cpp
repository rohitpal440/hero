/***
 * Write a program to print all the LEADERS in the array. An element is leader if it is
 * greater than all the elements to its right side. The rightmost element is always a leader.
 ***/

#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> &array) {
    for(auto it: array)
        cout << it << " ";
    cout << endl;
}


vector<int> getLeaderValues(const vector<int> &array) {
    vector<int> leaders;
    int max = array[array.size() - 1];
    leaders.push_back(max);
    for (int i = array.size() - 1; i >= 0; i--) {
        if (max < array[i]) {
            leaders.push_back(array[i]);
            max = array[i];
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    vector<int> array = {16, 17, 4, 3, 5, 2};
    printArray(getLeaderValues(array));
    return 0;
}
