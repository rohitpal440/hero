/***
 * There is an island nearby the cost which has crude oil burried
 * on it. The M natural oil is burried in M areas along the
 * costline creating a circle shape. The amount of burried crude
 * oil in each area is denoted as Ci toward the clockwise
 * direction (1 <= M). N oil Companies are showing interest in
 * participating in oil development on the island. However, since
 * a conflict among the companies may happen, the oil burried
 * areas are going to be divided and distributed to each company
 * with the following way:
 * 1. The oil is burried under the nearby cost will be distributed
 *    to N companies as fair as possible.
 * 2. When the difference between oil company having most oil and
 *    the company having least oil is minimum then distribution is
 *    considered fair.
 * 3. The oil buried areas that an oil company secured must be
 *    adjacent to one another. Thu when there are several oil
 *    buried area of a company, there cannot be any oil burried
 *    area of another company between them.
 * 4. All of the oil burried must be allocated to the companies.
 *    Each area cannot be allocated to more than one company.
 *
 * Constraints:
 * 2 <= N <= 25
 * N <= M <= 50
 * 1 <= Ci <= 100000
 * Ci refers to the amount of buried oil in the ith area
 * (clockwise direction)
 *
 * Input:
 * N M
 * C1 C2 ... Cm
 *
 * Output:
 * Difference between oil company having most oil and the company
 * having least oil (fair distribution)
 *
 * Example:
 * Input:
 * 2 4
 * 6, 13, 10, 2
 *
 * Output:
 * 5 //Explanation: [6,2,10] [13]
 ***/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct PartitionResult {
    int min;
    int max;
    vector< pair<int, int> > range;
};

PartitionResult partitionArray(const vector<int> &array, int k) {
    vector<int> prefixSum(array);
    for (int i = 1; i < array.size(); i++)
        prefixSum[i] += prefixSum[i-1];
    vector< vector<int> > maxSumPartition(array.size(), vector<int> (k));
    vector< vector<int> > partitionPoints(array.size() - 1 , vector<int> (k - 1));
    for (int i = 0; i < array.size(); i++)
        maxSumPartition[i][0] = prefixSum[i];
    for (int i = 0; i < k; i++)
        maxSumPartition[0][i] = array[0];
    for (int i = 1; i < array.size(); i++) {
        for ( int j = 1; j < k; j++) {
            maxSumPartition[i][j] = INT_MAX;
            for ( int x = 0; x < i; x++) {
                int maxSum = max(maxSumPartition[x][j-1], prefixSum[i] - prefixSum[x]);
                if (maxSum < maxSumPartition[i][j]) {
                    maxSumPartition[i][j] = maxSum;
                    partitionPoints[i-1][j-1] = x;
                }
            }
        }
    }
    int groupEnd = array.size() - 1;
    vector< pair<int, int> > groups(k);
    int groupMaxSum = maxSumPartition[groupEnd][k - 1];
    int groupMinSum = INT_MAX;
    for ( int i = k - 2; i >= 0; i--){
        int groupStart = partitionPoints[groupEnd - 1][i];
        groupMinSum = groupMinSum > (prefixSum[groupEnd] - prefixSum[groupStart]) ? (prefixSum[groupEnd] - prefixSum[groupStart]) : groupMinSum;
        groups[i+1] = make_pair(groupStart + 1, groupEnd);
        groupEnd = groupStart;
    }
    groups[0] = make_pair(0, groupEnd);
    groupMinSum = groupMinSum > prefixSum[groupEnd] ? prefixSum[groupEnd] : groupMinSum;
    return {groupMinSum, groupMaxSum, groups};
}

int fairDistrubutionDifference(const vector<int> &array, int k) {
    vector<int> tempArray(array);
    int difference = INT_MAX;
    for (int i = 0; i < tempArray.size(); i++) {
        rotate(tempArray.begin(), tempArray.begin() + (i > 0 ? 1 : 0), tempArray.end());
        auto result = partitionArray(tempArray, k);
        difference = difference > (result.max - result.min) ? (result.max - result.min) : difference;
    }
    return difference;
}

int main() {
//    vector<int> array = {6, 13, 10, 2}; // k = 2 => 5
//    vector<int> array = {6, 13, 2, 10}; // k = 2 => 1
    vector<int> array = {100, 92 , 133, 201, 34, 34, 34, 94, 108};//k=4 => 29
//    vector<int> array = {32, 42, 9, 27, 31, 18, 9, 2, 47, 36, 43, 33, 29, 32, 32, 48}; // k = 6 => 24
    int k = 4;
    cout << fairDistrubutionDifference(array, k) << endl;
}
