/***
 * K’th largest element in a stream
 * Given an infinite stream of integers, find the k’th largest element
 * at any point of time.
 *
 * Input:
 * stream[] = {10, 20, 11, 70, 50, 40, 100, 5, ...}
 * k = 3
 *
 * Output:    {_, _, 10, 11, 20, 40, 50,  50, ...}
 ***/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KthLargestElementFinder {
    priority_queue<int, vector<int>, greater<int> > pq;
    size_t frameSize;
public:
    KthLargestElementFinder(size_t frameSize) {
        this->frameSize = frameSize;
    }
    pair<bool, int> getKthLargestElement() {
        if (pq.size() == frameSize) {
            return make_pair(true, pq.top());
        } else {
            return make_pair(false, -1);
        }
    }

    void insertElement(int element) {
        if (pq.size() < frameSize) {
            pq.push(element);
        } else if (pq.top() < element) {
            pq.pop();
            pq.push(element);
        }
    }
};



int main() {
    vector<int> array = {10, 20, 11, 70, 50, 40, 100, 5};
    KthLargestElementFinder finder(3);
    for (auto element: array) {
        finder.insertElement(element);
        auto result = finder.getKthLargestElement();
        if (result.first) {
            cout << result.second << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
    return 0;
}
