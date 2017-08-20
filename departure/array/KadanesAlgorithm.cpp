/***
 Kadane's Algorithm:
 Given an array containing both negative and positive integers.
 Find the contiguous sub-array with maximum sum.
 ***/
#include <iostream>
#include <vector>

using namespace std;

pair<int, pair<size_t, size_t> > getContigousMaxSum(const vector<int> &array) {
    pair<int, pair<size_t, size_t> > result = make_pair(array[0], make_pair(0, 0));
    pair<int, pair<size_t, size_t> > tempResult = make_pair(array[0], make_pair(0, 0));
    for (size_t i = 1; i < array.size(); i++) {
        if (array[i] > tempResult.first + array[i]) {
            tempResult = make_pair(array[i], make_pair(i, i));
        } else {
            tempResult.first = tempResult.first + array[i];
            tempResult.second.second = i;
        }
        if (tempResult.first > result.first) {
            result = tempResult;
        }
    }
    return result;
}

int main() {
    vector<int> array = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    pair<int, pair<size_t, size_t> > result = getContigousMaxSum(array);
    cout << "Maximum sum: " << result.first << endl;
    cout << "Sub-Array : ";
    for (auto i = result.second.first; i <= result.second.second; i++)
        cout << array[i] << " ";
    cout << endl;
    return 0;
}
