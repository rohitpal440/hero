/*
 ID: rohitpa4
 PROG: milk
 LANG: C++11
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    freopen("milk.in", "r", stdin);
    freopen ("milk.out","w",stdout);
    int demand, numberOfFarmers;
    vector< pair<int, int> > farmers;
    cin >> demand >> numberOfFarmers;
    for (int i = 0; i < numberOfFarmers; i++) {
        int milkRate, milkVolume;
        cin >> milkRate >> milkVolume;
        farmers.push_back(make_pair(milkRate, milkVolume));
    }
    sort(farmers.begin(), farmers.end());
    int totalCost = 0;
    for (auto farmer: farmers) {
        if (demand > farmer.second) {
            demand -= farmer.second;
            totalCost += farmer.first * farmer.second;
        } else {
            totalCost += farmer.first  * demand;
            break;
        }
    }
    cout << totalCost << endl;
    return 0;
}
