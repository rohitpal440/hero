/***
 * Given arrival and departure times of all trains that reach a railway station,
 * find the minimum number of platforms required for the railway station so that
 * no train waits.
 *
 * | 0900 | 0940 | 0950 | 1100 | 1500 | 1800
 * | 0910 | 1200 | 1120 | 1130 | 1900 | 2000
 * output : 3
 ***/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct train {
    int arrivalTime;
    int departureTime;
    bool operator<(const train& rhs) const {
        return this->departureTime > rhs.departureTime;
    }
    static bool compareTrainWithArrivalTime(train &lhs, train &rhs) {
        return lhs.arrivalTime < rhs.arrivalTime;
    }
};

size_t getPlatformCount(const vector< train > &trains) {
    if (trains.size() == 0)
        return 0;
    priority_queue<train> platforms;
    platforms.push(trains[0]);
    for (int i = 1; i < trains.size(); i++) {
        auto it = platforms.top();
        if (it.departureTime < trains[i].arrivalTime) {
            platforms.pop();
        }
        platforms.push(trains[i]);
    }
    return platforms.size();
}

int main() {
    vector< train > trains = { {900, 910}, {950, 1120}, {1500, 1900}, {940, 1200}, {1100, 1130}, {1800, 2000}};
    sort(trains.begin(), trains.end(), train::compareTrainWithArrivalTime);
    cout << getPlatformCount(trains) << endl;
    return 0;
}
