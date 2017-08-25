/***
 * Given an array A your task is to tell at which position the equilibrium first occurs in the array.
 * Equilibrium position in an array is a position such that the sum of elements below it is equal to
 * the sum of elements after it.
 ***/

#include <iostream>
#include <vector>
using namespace std;


void printArray(const vector<int> &array) {
    for(auto it: array)
        cout << it << "";
    cout << endl;
}

    //Time Complexity: O(n)
    //Space Complexity: O(n)

pair<bool, size_t> getEquilibriumIndex(const vector<int> & array) {
    if (array.size() < 3) {
        return make_pair(false, 0);
    }
    size_t arraySize = array.size();
    vector<int> sumArray(array);
    for (size_t i = 1; i < arraySize; i++)
        sumArray[i] += sumArray[i-1];
    int rightSum = array[arraySize - 1];
    for (int i = arraySize - 2; i >= 0; i--) {
        if(i - 1 > 0 && sumArray[i-1] == rightSum)
            return make_pair(true, i);
        rightSum += array[i];
    }
    return make_pair(false, 0);
}

int main() {
    vector<int> array = {1, 3, 5, 2, 9};
    pair<bool, size_t> result = getEquilibriumIndex(array);
    if (result.first) {
        cout << "Found Equilibrium Index: " << result.second << endl;
    } else {
        cout << "No Equilibrium Point Exists" << endl;
    }
    return 0;
}
