/***
* Given an array of integers, sort the array according to
* frequency of elements. For example, if the input array 
* is {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12}, then modify the
* array to {3, 3, 3, 3, 2, 2, 2, 12, 12, 4, 5}.
* If frequencies of two elements are same, print them in
* increasing order.
***/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void printArray(const vector<int> array) {
    for (auto it : array)
        cout << it << " ";
    cout << "\b" << endl;
}

void sortByFrequency(vector<int> &array) {
    unordered_map<int, int> map;
    for( auto it: array) {
        if (map.find(it) == map.end())
            map[it] = 1;
        else
            map[it]++;
    }
    sort(array.begin(), array.end(), [&map](int lhs, int rhs) {
        if (map[lhs] == map[rhs])
            return lhs < rhs;
        return map[lhs] > map[rhs];
    });
}

int main() {
    vector<int> array = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};
    sortByFrequency(array);
    printArray(array);
}
