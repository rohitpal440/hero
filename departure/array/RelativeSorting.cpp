/***
 * Given two array A1[] and A2[], sort A1 in such a way that the
 * relative order among the elements will be same as those  in A2.
 * For the elements not present in A2. Append them at last in sorted
 * order. It is also given that the number of elements in A2[] are
 * smaller than or equal to number of elements in A1[] and A2[] has
 * all distinct elements.
 *
 * Input: A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
 * A2[] = {2, 1, 8, 3}
 * Output: A1[] = {2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}
 ***/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void printArray(const vector<int> array) {
    for (auto it : array)
        cout << it << " ";
    cout << endl;
}

vector<int> getRelativeSortedArray(const vector<int> &array, const vector<int> &refArray) {
    unordered_map<int, int> map;
    for( auto it: array) {
        if (map.find(it) == map.end())
            map[it] = 1;
        else
            map[it]++;
    }
    vector<int> tempArray;
    unordered_map<int, bool> found;
    for (int i = 0; i < refArray.size(); i++) {
        if (map.find(refArray[i]) != map.end()) {
            for(int j = 0; j < map[refArray[i]]; j++) {
                tempArray.push_back(refArray[i]);
            }
            found[refArray[i]] = true;
        }
    }
    int unsortedStartIndex = tempArray.size();
    for (int i = 0; i < array.size(); i++) {
        if (found.find(array[i]) == found.end())
            tempArray.push_back(array[i]);
    }
    sort(tempArray.begin() + unsortedStartIndex, tempArray.end());
    return tempArray;
}

int main() {
    vector<int> array = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    vector<int> refArray = {2, 1, 8, 3};
    printArray(getRelativeSortedArray(array, refArray));
}
