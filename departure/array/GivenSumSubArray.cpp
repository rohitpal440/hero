/***
 Given an unsorted array of integers, find a continuous sub-array
 which adds to a given number.
 ***/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/***
 *Function below works only for array of positive integers, Similar to Kadane's Algorithm
 ***/
    //pair<bool, pair<size_t, size_t> > findSubArrayOfSum(const vector<int> & array, const int sum) {
    //    pair<bool, pair<size_t, size_t> > result = make_pair(false, make_pair(0, 0));
    //    int tempSum = 0;
    //    for (int i = 0; i < array.size(); i++) {
    //        if (tempSum + array[i] <= sum) {
    //            tempSum += array[i];
    //            result.second.second = i;
    //            if (tempSum == sum) {
    //                result.first = true;
    //                break;
    //            }
    //        } else {
    //            tempSum =  0;
    //            result = make_pair(false, make_pair(i, i));
    //            i--;
    //        }
    //    }
    //    return result;
    //}

/***
 *Function below works for array of positive as well as negative integers
 ***/

pair<bool, pair<size_t, size_t> > findSubArrayOfSum(const vector<int> & array, const int sum) {
    pair<bool, pair<size_t, size_t> > result = make_pair(false, make_pair(0, 0));
    int tempSum = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < array.size(); i++) {
        tempSum = tempSum + array[i];
        if (tempSum == sum) {
            return make_pair(true, make_pair(0, i));
        }
        if (map.find(tempSum - sum) != map.end()) {
            return make_pair(true, make_pair(map[tempSum - sum] + 1, i));
        }
        map[tempSum] = i;
    }
    return result;
}

int main() {
    int sum = 7;
        //    vector<int> array = {6, 2, 1, 1, 4};
    vector<int> array = {6, 5, 1, 2, 1, 4};
        //    vector<int> array = {6, -10, 1, 2, 1, 4};
        //    vector<int> array = {6, -10, 11, 2, 1, 4};
        //    vector<int> array = {-10, 6, 1, 2, 1, 4};
    pair<bool, pair<size_t, size_t> > result = findSubArrayOfSum(array, sum);
    if (result.first) {
        cout << "Sub Array with given sum : " << sum << endl;
        for (size_t i = result.second.first; i <= result.second.second; i++)
            cout << array[i] << " ";
        cout << endl;
    } else {
        cout << "No Such sub array found with given sum : " << sum << endl;
    }
    return 0;
}
