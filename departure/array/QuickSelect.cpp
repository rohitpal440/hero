/***
 * QuickSelect Algorithm:
 * Find kth largest/smallest element
 ***/
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

void printArray(const vector<int> &array) {
    for (auto it: array)
        cout << it << " ";
    cout << endl;
}

int partition(vector<int> &array, int start, int end, bool greater) {
    int left = start;
    int right = end - 1;
    swap(array[start + rand() % (end-start + 1)], array[end]);
    int pivot = array[end];
    while(left < right) {
        if (greater) { // decreasing order
            while(left < right && pivot > array[right])
                right--;
            while (left <= right && pivot < array[left])
                left++;
        } else { // increasing order
            while(left < right && pivot < array[right])
                right--;

            while (left <= right && pivot > array[left])
                left++;
        }
        if (left < right)
            swap(array[left], array[right]);
    }
    if (greater) { // decreasing order
        if (left < end && pivot > array[left]) { // e.g. [2,1], [1,2]
            swap(array[left], array[end]);
        }
    } else { // increasing order
        if (left < end && pivot < array[left]) {
            swap(array[left], array[end]);
        }
    }
    return left;
}

int quickSelect(bool isGreater, int k, vector<int> &array, int start, int end) {
    if (k > 0 && k <= array.size() && start <= end) {
        int pivotIndex = partition(array, start, end, isGreater);
        if (k - 1 == pivotIndex) {
            return array[pivotIndex];
        } else if ( k - 1  < pivotIndex) {
            return quickSelect(isGreater, k, array, start, pivotIndex-1);
        } else  {
            return quickSelect(isGreater, k, array, pivotIndex+1, end);
        }
    }
    return isGreater ? INT_MIN : INT_MAX;
}


int main() {
    srand(time(nullptr));
        //            int a[] = {2, 1};
        //    int a[] = {1,2};
    int a[] = {6,2,4,8,3,9,1,10,7,5};
        //    int a[] = {1,2,3,4,5,6,7,8,9,10};
        //    int a[] = {10,9,8,7,6,5,4,3,2,1};
    const int k = 7;
    vector<int> array(a, a + (sizeof(a)/sizeof(int)));
    cout << "printing "<< k << "th smallest element" << endl;
    cout << quickSelect(false, k, array, 0, int(array.size()) - 1) << endl;
    printArray(array);
    cout << "printing "<< k << "th largest element" << endl;
    cout << quickSelect(true, k, array, 0, int(array.size()) - 1) << endl;
}
