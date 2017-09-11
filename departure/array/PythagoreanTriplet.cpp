/***
 * Pythagorean Triplet Problem:
 * Given an array find if 3 numbers exists such that a^2 + b^2 = c^2
 ***/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool getPythogoreanTriplet(const vector<int> &array) {
    vector<int> tempArray(array);
    sort(tempArray.begin(), tempArray.end());
    unordered_map<int, int> map;
    for (int i = 0; i <tempArray.size(); i++) {
        tempArray[i] *= tempArray[i];
        map[tempArray[i]] = i;
    }
    for (int i = tempArray.size() - 1; i >= 0; i--)
        for(int j = i - 1; j >= 0; j--)
            if (map.find(tempArray[i] - tempArray[j]) != map.end())
                return true;
    return false;
}

int main() {
    vector<int> array = {3, 2, 4, 6, 5};
    cout << "Triplets found: " << (getPythogoreanTriplet(array) ? "YES" : "NO") << endl;
    return 0;
}
