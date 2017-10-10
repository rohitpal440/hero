/*
 ID: rohitpa4
 PROG: milk2
 LANG: C++11
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> analyseMilkingSlots(const vector<pair<int, int> > &milkingSlots) {
    int startTime = 0;
    int endTime = 0;
    int noCowBeingMilkedTime = 0;
    int atLeastOneCowMilkedTime = 0;
    bool isMilkingStarted = false;
    for (auto slot: milkingSlots) {
        if (slot.first > endTime) {
            if (isMilkingStarted) {
                noCowBeingMilkedTime = max(noCowBeingMilkedTime, slot.first - endTime);
                atLeastOneCowMilkedTime = max(atLeastOneCowMilkedTime, endTime - startTime);
            }
            startTime = slot.first;
            endTime = slot.second;
            isMilkingStarted = true;
        } else  {
            endTime = max(endTime, slot.second);
        }
    }
    atLeastOneCowMilkedTime = max(atLeastOneCowMilkedTime, endTime - startTime);
    return make_pair(atLeastOneCowMilkedTime, noCowBeingMilkedTime);
}

int main(int argc, const char * argv[]) {
    freopen("milk2.in", "r", stdin);
    freopen ("milk2.out","w",stdout);
    int farmersCount;
    cin >> farmersCount;
    vector< pair<int, int> > milkingSlots(farmersCount);
    for (int i = 0; i < farmersCount; i++) {
        int startTime, endTime;
        cin >> startTime >> endTime;
        milkingSlots[i] = make_pair(startTime, endTime);
    }
    sort(milkingSlots.begin(), milkingSlots.end(), [](pair<int, int> lhs, pair<int, int> rhs) -> bool{
        return lhs.first < rhs.first;
    });
    auto result = analyseMilkingSlots(milkingSlots);
    cout << result.first << " " << result.second << endl;
    return 0;
}
