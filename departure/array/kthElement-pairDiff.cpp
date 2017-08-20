/***

 Given an array of integers of size N. You need to find out the difference
 between each pair of integer. If difference is not present in array insert it
 into array and repeat difference procedure. Do it untill array become stable.
 After array become stable print kth largest element if they are sorted in
 ascending order.

 ***/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> myMap;

void printArray(const vector<int> &array) {
    for(auto i : array)
        cout << i << " ";
    cout << endl;
}

vector<int> getProcessedArray(const vector<int> &array, int tillIndex) {
    vector<int> newArray(array);
    size_t size = array.size();
    for(int i = size - 1; i >= tillIndex; i--) {
        for(int j = i - 1; j >= 0; j--) {
            int diff = abs(array[i] - array[j]);
            if (myMap.find(diff) == myMap.end()) {
                myMap[diff] = true;
                newArray.push_back(diff);
            }
        }
    }
    printArray(newArray);
    return newArray;
}

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int arraySize, KthElement;
        vector<int> array;
        myMap.clear();
        cin >> arraySize;
        for(int i = 0; i< arraySize; i++) {
            int temp;
            cin >>temp;
            array.push_back(temp);
            myMap[temp] = true;
        }
        cin >> KthElement;
        bool shouldProcess = false;
        int tillIndex = 0;
        do {
            vector<int> newArray = getProcessedArray(array, tillIndex);
            if (newArray.size() != array.size()) {
                shouldProcess = true;
                tillIndex = array.size() - 1  + (array.size() - newArray.size());
                array = newArray;
            } else {
                shouldProcess = false;
            }
        } while (shouldProcess);
        sort(array.begin(), array.end());
        printArray(array);
        cout << array[KthElement-1] << endl;
    }
}
