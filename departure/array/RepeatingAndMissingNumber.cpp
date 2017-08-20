/***
 Given an unsorted array of size n. Array elements are in range from 1 to n.
 One number from set {1, 2, …n} is missing and one number occurs twice in array.
 Find these two numbers
 ***/

    // Time complexity of program is O(n)
    // Space Complexity of program is O(n)
    // Additional space consumption can be avoided if Array mutation is allowed
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> getRepeatingAndMissingNumber(const vector<int> & array) {
    vector<int> tempArray(array);
    pair<int, int> result = make_pair(0, 0);
    for (int it: tempArray) {
        it  = abs(it);
        if (tempArray[it - 1] > 0) {
            tempArray[it - 1] = -tempArray[it-1];
        } else {// repeating number
            result.first = it;
        }
    }

    for (int i = 0; i < tempArray.size(); i++) {
        if (tempArray[i] > 0) {
            result.second = i + 1;
            break;
        }
    }
    return result;
}

int main() {
    int n = 7; // useless for now
    vector<int> array = {4, 3, 6, 2, 1, 1};
    pair<int, int> result = getRepeatingAndMissingNumber(array);
    cout << "Repeating Number is: " << result.first << endl;
    cout << "Missing Number is: " << result.second << endl;
    return 0;
}
