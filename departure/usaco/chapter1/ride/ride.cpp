/*
 ID: rohitpa4
 PROG: ride
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string comet, group;
    int cometProduct = 1, groupProduct = 1;
    fin >> comet >> group;
    for (int i = 0; i < 6; i++) {
        if ( i < comet.size())
            cometProduct *= (comet[i] - 'A') + 1;
        if ( i < group.size())
            groupProduct *= (group[i] - 'A') + 1;
    }
    fout << (cometProduct % 47 == groupProduct % 47 ? "GO" : "STAY") << endl;
    return 0;
}
