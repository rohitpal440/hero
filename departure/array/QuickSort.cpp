/***
 * QuickSort Algorithm
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

int partition(vector<int> &array, int start, int end) {
    int left = start;
    int right = end - 1;
    swap(array[start + rand() % (end-start + 1)], array[end]); // randomized quick sort
    int pivot = array[end];
    while(left < right) {
        while(left < right && pivot < array[right])
            right--;
        while (left <= right && pivot > array[left])
            left++;
        if (left < right)
            swap(array[left], array[right]);
    }
    if (left < end && pivot < array[left]) { // e.g. [2,1], [1,2]
        swap(array[left], array[end]);
    }
    return left;
}

    /***
    *Another way of partitioning
    ***/

    //int partition(vector<int> &array, int start, int end) {
    //    int pivot = start;
    //        //    uncomment for randomized quicksort
    //        //    swap(array[start + rand() % (end - start + 1)], array[end]);
    //    for (int i = start; i < end; i++)
    //        if (array[i] < array[end])
    //            swap(array[i], array[pivot++]);
    //    swap(array[pivot], array[end]);
    //    return pivot;
    //}

void quicksort(vector<int> &array, int start, int end) {
    if (start < end) {
        int pivotIndex = partition(array, start, end);
        quicksort(array, start, pivotIndex-1);
        quicksort(array, pivotIndex+1, end);
    }
}

int main() {
    srand(time(nullptr));// for random seeding
        //    int a[] = {2,1};
    int a[] = {1,2};
        //    int a[] = {6,2,4,8,3,9,1,10,7,5};
        //    int a[] = {1,2,3,4,5,6,7,8,9,10};
        //    int a[] = {10,9,8,7,6,5,4,3,2,1};
    vector<int> array(a, a + (sizeof(a)/sizeof(int)));
    quicksort(array, 0, int(array.size()) - 1);
    printArray(array);
}
