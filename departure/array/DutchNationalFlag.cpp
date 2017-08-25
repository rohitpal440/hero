/***
 * Dutch National Flag Problem
 * Given an array A[] consisting 0s, 1s and 2s, write a function that sorts A[].
 * The functions should put all 0s first, then all 1s and all 2s in last.*
 ***/

#include <iostream>
#include <vector>
using namespace std;
void printArray(const vector<int> &array) {
    for (auto it : array)
        cout << it << " ";
    cout << endl;
}

void sortArray(vector<int> &array) {
    if (array.size() < 2) {
        return;
    }
    size_t low = 0;
    size_t mid = 0;
    size_t high = array.size() - 1;
    while (mid <= high) {
        if (array[mid] == 0 ) {
            if (low == mid) {
                low++;
                mid++;
                continue;
            }
            swap(array[low++], array[mid++]);
        } else if (array[mid] == 1) {
            mid++;
        } else {
            swap(array[mid], array[high--]);
        }
    }
}

int main() {
    vector<int> array = {2, 2, 2, 1, 1, 1, 0};
    sortArray(array);
    printArray(array);
    return 0;
}
