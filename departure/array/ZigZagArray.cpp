/***
 * Given an array of distinct elements, rearrange the elements of
 * array in zig-zag fashion in O(n) time. The converted array should
 * be in form a < b > c < d > e < f.The relative order of elements is
 * same in the output i.e you have to iterate on the original array only.
 ***/

#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> array) {
    for (auto it : array)
        cout << it << " ";
    cout << endl;
}

void convertArrayToZigZag(vector<int> &array) {
    bool up = true;
    for (int i = 0; i < array.size() - 1; i++) {
        if (up && !(array[i] < array [i+1])) {
            swap(array[i], array[i+1]);
        } else if (!up && !(array[i] > array[i+1])) {
            swap(array[i], array[i+1]);
        }
        up = !up;
    }
}

int main() {
    vector<int> array = {4, 3, 7, 8, 6, 2, 1};
    convertArrayToZigZag(array);
    printArray(array);
}
