/***
* Problem:
* Given n non-negative integers in array representing an elevation
* map where the width of each bar is 1, compute how much water it
* is able to trap after raining.
***/

#include <iostream>
#include <vector>
using namespace std;

int getTrappedWater(const vector<int> &array) {
    const int arraySize = int(array.size());
    vector<int> leftTower(arraySize, 0), rightTower(arraySize,0);
    for (int i = 1; i < arraySize; i++) {
        leftTower[i] = max(leftTower[i-1], array[i-1]);
        rightTower[arraySize - 1 - i] = max(rightTower[arraySize - i], array[arraySize - i]);
    }
    int totalWater = 0;
    for (int i = 1; i < (arraySize - 1); i++)
        if (array[i] < min(leftTower[i], rightTower[i]))
            totalWater += min(leftTower[i], rightTower[i]) - array[i];
    return totalWater;
}

int main() {
    vector<int> array = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << getTrappedWater(array) << endl;
    return 0;
}
