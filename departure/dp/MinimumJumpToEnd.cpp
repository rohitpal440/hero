#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> &array) {
    for (auto it: array)
        cout << it << " ";
    cout << endl;
}

// minimum number of jump to reach the end of array containing +ve integers
pair<int, vector<int> > minNumberOfJumps(const vector<int> &array) {
    if (array.empty() || array.size() == 1)
        return make_pair(0, vector<int>(0));
    if (array[0] == 0)
        return make_pair(INT_MIN, vector<int>(0));
    pair<int, vector<int> > jumps;
    jumps.second.push_back(0);
    pair<int,int> maxLadder = make_pair(array[0], 0);
    int stairsToClimb = array[0];
    for (int i = 1; i < array.size(); i++) {
        stairsToClimb--;
        if (i == array.size() - 1) {
            jumps.first++;
            jumps.second.push_back(i);
            break;
        }
        if (maxLadder.first < i + array[i])
            maxLadder = make_pair(i + array[i], i);
        if (stairsToClimb == 0) {
            if (maxLadder.first - i == 0)
                return make_pair(INT_MIN, vector<int>(0));;
            jumps.first++;
            jumps.second.push_back(maxLadder.second);
            stairsToClimb = maxLadder.first - i;
        }
    }
    return jumps;
}

int main() {
    vector<int> array = {2,2,4,9,1,1,1,1,1,1,3};//{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    auto result = minNumberOfJumps(array);
    cout << result.first << endl;
    cout << "Jumped on indexes" << endl;
    printArray(result.second);
}
