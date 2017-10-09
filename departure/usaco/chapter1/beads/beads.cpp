/*
 ID: rohitpa4
 PROG: beads
 LANG: C++11
 */

#include <iostream>
#include <string>
using namespace std;

string getBrokenNecklace(string necklace, int n) {
    string brokenNacklace = "";
    brokenNacklace += necklace.substr(n, necklace.size() - n);
    if (n != 0)
        brokenNacklace += necklace.substr(0, n);
    return brokenNacklace;
}

int collectBeads(string necklace) {
    int start = 0;
    int collectedBeads = 0;
    pair< bool, char> firstBead;
    pair<bool, char> secondBead;
    for (; start < necklace.size(); start++) {
        if (!firstBead.first && necklace[start] != 'w') {// if first bead not found
            firstBead.first = true;
            firstBead.second = necklace[start];
        } else if (necklace[start] != 'w' && necklace[start] != firstBead.second) {
            break;
        }
        collectedBeads++;
    }
    if (start == necklace.size())
        return collectedBeads;
    for (int i = necklace.size() - 1; i >= start; i--) {
        if (!secondBead.first && necklace[i] != firstBead.second && necklace[i] != 'w') {
            secondBead.first = true;
            secondBead.second = necklace[i];
        } else if (secondBead.first && necklace[i] != 'w' && necklace[i] != secondBead.second) {
            break;
        }
        collectedBeads++;
    }
    return collectedBeads;
}

int main(int argc, const char * argv[]) {
    freopen("beads.in", "r", stdin);
    freopen ("beads.out","w",stdout);
    int necklaceSize;
    string necklace;
    cin >> necklaceSize;
    cin >> necklace;
    int maxCollectedBeads = 0;
    for (int i = 0; i < necklace.size(); i++) {
        string brokenNecklace = getBrokenNecklace(necklace, i);
        maxCollectedBeads = max(maxCollectedBeads, collectBeads(brokenNecklace));
    }
    cout << maxCollectedBeads << endl;
    return 0;
}
