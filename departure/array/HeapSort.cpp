    // HeapSort
#include <iostream>
#include <vector>
using namespace std;

bool compareElement(int a, int b, bool greater) {
    if (greater) {
        return a > b;
    }
    return a < b;
}

void heapify(vector<int> &array, int size, int rootIndex, bool isMaxHeap = true) {
    int largestElementIndex = rootIndex;
    int leftChildIndex = 2 * rootIndex + 1;
    int rightChildIndex = 2 * rootIndex + 2;
    if (leftChildIndex < size && compareElement(array[largestElementIndex], array[leftChildIndex], !isMaxHeap)) {
        largestElementIndex = leftChildIndex;
    }
    if (rightChildIndex < size && compareElement(array[largestElementIndex], array[rightChildIndex], !isMaxHeap)) {
        largestElementIndex = rightChildIndex;
    }
    if (largestElementIndex != rootIndex) {
        swap(array[largestElementIndex], array[rootIndex]);
        heapify(array, size, largestElementIndex, isMaxHeap);
    }
}

void heapSort(vector<int> &array, bool inAscendingOrder = true) {
    for (int i = (int)array.size() / 2 - 1; i >=0; i--) {
        heapify(array, (int)array.size(), i, inAscendingOrder);
    }
    for (int i = (int)array.size() - 1; i >= 0; i--) {
        swap(array[i], array[0]);
        heapify(array, i, 0, inAscendingOrder);
    }
}

void printArray(const vector<int> &array) {
    for (auto element: array)
        cout << element << " ";
    cout << endl;
}

int main() {
    vector<int> array = {10,9,11,7,12,17,6,5};
    heapSort(array, false); // descending order
    printArray(array);
    heapSort(array); // ascending order
    printArray(array);
}
