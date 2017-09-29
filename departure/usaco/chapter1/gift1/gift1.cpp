/*
 ID: rohitpa4
 PROG: gift1
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    int friendCount;
    fin >> friendCount;
    vector <string> friends(friendCount);
    unordered_map<string, int> money;
    for (int i = 0; i < friendCount; i++) {
        fin >> friends[i];
        money.insert(make_pair(friends[i], 0));
    }
    for ( int i = 0; i < friends.size(); i++) {
        string giftGiver;
        int moneyToDistribute, numberOfPeople, moneyPerPerson;
        fin >> giftGiver >> moneyToDistribute >> numberOfPeople;
        moneyPerPerson = moneyToDistribute / (numberOfPeople == 0 ? 1 : numberOfPeople);
        for (int j = 0; j < numberOfPeople; j++) {
            string giftReceiver;
            fin >> giftReceiver;
            money[giftReceiver] += moneyPerPerson;
            money[giftGiver] -= moneyPerPerson;
        }
    }
    for (auto it: friends) {
        fout << it << " "  << money[it] << endl;
    }
    return 0;
}
