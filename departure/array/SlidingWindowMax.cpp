/***
 * Sliding Window Maximum :
 * Given an array and an integer k, find the maximum for each and every contiguous
 * subarray of size k.
 ***/
#include<iostream>
#include<vector>
#include<deque>

using namespace std;

void printArray(const vector<int> &array) {
    for(auto it: array)
        cout << it << " ";
    cout << endl;
}

//there can be another way in which we divide array into windowSize and try to find max
//from left->Right(LR) and Right->left(RL)
//then calculate max using max(LR[index+windowSize-1], RL[index])
//https://stackoverflow.com/a/17249084/5751046

vector<int> getSlidingWindowMax(const vector<int> &array, const size_t windowSize) {
    vector<int> result;
    deque<size_t> dq;
    for (size_t i = 0; i < windowSize; i++) {
        while(!dq.empty() && array[i] >= array[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for (size_t i = windowSize; i < array.size(); i++) {
        result.push_back(array[dq.front()]);
        while(!dq.empty() && array[i] >= array[dq.back()])
            dq.pop_back();
        while(!dq.empty() && dq.front() <= i - windowSize)
            dq.pop_front();
        dq.push_back(i);
    }
    result.push_back(array[dq.front()]);
    return result;
}

int main() {
    vector<int> array {1, -2, 5, 6, 0, 9, 8, -1, 2, 0};
    printArray(getSlidingWindowMax(array, 3));
    return 0;
}
