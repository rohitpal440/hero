/***
 * Given an array of n positive integers. Write a program to find the sum
 * of maximum sum subsequence of the given array such that the integers in
 * the subsequence are sorted in increasing order.
 ***/

#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<int> &array) {
    for (auto it: array)
        cout << it << " ";
    cout << endl;
}

pair<int, vector<int> > maximumSumIncreasingSeq(const vector<int> &array) {
    vector<int> sumArray(array);
    vector<int> parent(array.size());
    for (int i = 0; i < array.size(); i++)
        parent[i] = i;
    for (int  i = 1; i < array.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if ( array[i] > array[j] && sumArray[i] < sumArray[j] + array[i]) {
                sumArray[i] = sumArray[j] + array[i];
                parent[i] = j;
            }
        }
    }
    auto maxElement = max_element(sumArray.begin(), sumArray.end());
    size_t indexOfMaxElement = distance(sumArray.begin(), maxElement);
    vector<int> subSequence;
    while (indexOfMaxElement != parent[indexOfMaxElement]) {
        subSequence.push_back(array[indexOfMaxElement]);
        indexOfMaxElement = parent[indexOfMaxElement];
    }
    subSequence.push_back(array[indexOfMaxElement]);
    reverse(subSequence.begin(), subSequence.end());
    return make_pair(*maxElement, subSequence);
}

int main() {
    vector<int> array = {1, 101, 2, 3, 100, 4, 5};
        //    vector<int> array = {10, 5, 4, 3};
    auto result = maximumSumIncreasingSeq(array);
    cout << "Max sum is : " << result.first << endl;
    cout << "Max sum increase subsequence is: ";
    printArray(result.second);
    return 0;
}
