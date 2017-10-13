/*
 ID: rohitpa4
 PROG: barn1
 LANG: C++11
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool comparator (pair<int, int> lhs, pair<int, int> rhs) {
    return lhs.first > rhs.first;
};

int main(int argc, const char * argv[]) {
    freopen("barn1.in", "r", stdin);
    freopen ("barn1.out","w",stdout);
    int numberOfBoards, totalNumberOfStalls, numberOfCows;
    vector<int> cowLocations;
    cin >> numberOfBoards >> totalNumberOfStalls >> numberOfCows;
    for (int i = 0; i < numberOfCows; i++) {
        int location;
        cin >> location;
        cowLocations.push_back(location);
    }
    sort(cowLocations.begin(), cowLocations.end());
    if (numberOfBoards == 1) {
        cout << cowLocations[numberOfCows - 1] - cowLocations[0] + 1 << endl;
        return 0;
    } else if (numberOfBoards >= numberOfCows) {
        cout << numberOfCows << endl;
        return 0;
    }
    
    priority_queue< pair<int, int>, vector< pair<int, int> >, decltype(&comparator) > topGaps(&comparator);
    for (int i = 1; i < cowLocations.size(); i++) {
        int gap = cowLocations[i] - cowLocations[i - 1];
        if (topGaps.empty() || topGaps.size() < numberOfBoards - 1) {
            topGaps.push(make_pair(gap, i - 1));
        } else if (topGaps.top().first < gap) {
            topGaps.pop();
            topGaps.push(make_pair(gap, i - 1));
        }
    }
    vector<int> dividersLocation;
    while (!topGaps.empty()) {
        auto gap = topGaps.top();
        dividersLocation.push_back(gap.second);
        topGaps.pop();
    }
    sort(dividersLocation.begin(), dividersLocation.end());
    int totalBoardLength = 0;
    int startIndex = 0;
    for (int i = 0; i < numberOfBoards; i++) {
        int endIndex;
        if (i == numberOfBoards - 1)
            endIndex = cowLocations.size() - 1;
        else
            endIndex = dividersLocation[i];
        totalBoardLength += cowLocations[endIndex] - cowLocations[startIndex] + 1;
        startIndex = endIndex + 1;
    }
    cout << totalBoardLength << endl;
    return 0;
}

