/*
 Problem:
 Given an integer N denoting the Length of a line segment.
 You need to cut the line segment in such a way that the cut
 length of a line segment each time is integer either x , y or z.
 and after performing all cutting operation the total number of
 cutted segments must be maximum.
*/
#include <iostream>
#include <vector>
using namespace std;

int getMaximumCut(const int rodLength, const vector<int> &cut) {
    vector<int> dp(rodLength + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < rodLength; i++) {
        if (dp[i] != -1) {
            dp[i + cut[0]] = max(dp[i] + 1, dp[i + cut[0]]);
            dp[i + cut[1]] = max(dp[i] + 1, dp[i + cut[1]]);
            dp[i + cut[2]] = max(dp[i] + 1, dp[i + cut[2]]);
        }
    }
    return dp[rodLength];
}

int main() {
    int rodLength = 5;
    vector<int> cut = {5,3,2};
    cout << getMaximumCut(rodLength, cut) << endl;
}
