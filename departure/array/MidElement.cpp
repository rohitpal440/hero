/***
 * Given an unsorted array of size N. Find the first element in array
 * such that all of its left elements are smaller and all right
 * elements to it are greater than it.
 ***/

#include <iostream>
#include <vector>
using namespace std;

int getPivotElementIndex(const vector<int> &array) {
    auto result = make_pair(array[0], false);
    int elementIndex = 0;
    for (int i = 1; i < array.size(); i++) {
        if (!result.second && result.first < array[i]) {
            result.first = array[i];
            elementIndex = i;
            result.second = true;
        } else if (array[i] < array[i-1] && result.first < array[i-1]) {
            result.first = array[i-1];
            result.second = false;
            elementIndex = i - 1;
        }
    }
    return result.second && (elementIndex != array.size() - 1) ? elementIndex : -1;
}

int main() {
    vector<int> array = {4, 3, 2, 7, 8, 9};
    auto result = getPivotElementIndex(array);
    cout << "array[" << result << "] = " << array[result] << endl;
}
