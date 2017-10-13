/*
 ID: rohitpa4
 PROG: namenum
 LANG: C++11
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

unordered_map<char, char> keyMap;

void initKeyMap() {
    keyMap['A'] = keyMap['B'] = keyMap['C'] = '2';
    keyMap['D'] = keyMap['E'] = keyMap['F'] = '3';
    keyMap['G'] = keyMap['H'] = keyMap['I'] = '4';
    keyMap['J'] = keyMap['K'] = keyMap['L'] = '5';
    keyMap['M'] = keyMap['N'] = keyMap['O'] = '6';
    keyMap['P'] = keyMap['R'] = keyMap['S'] = '7';
    keyMap['T'] = keyMap['U'] = keyMap['V'] = '8';
    keyMap['W'] = keyMap['X'] = keyMap['Y'] = '9';
}

string getSerialNumberStringFromName(string name) {
    string serialNumber;
    for (int i = 0; i < name.size(); i++) {
        serialNumber += keyMap[name[i]];
    }
    return serialNumber;
}

int main(int argc, const char * argv[]) {
    freopen("namenum.in", "r", stdin);
    freopen ("namenum.out","w",stdout);
    ifstream fin("dict.txt");
    string number;
    string name;
    bool foundAnyResult = false;
    cin >> number;
    initKeyMap();
    while(fin >> name) {
        if (number.size() == name.size()) {
            auto serialNumberString = getSerialNumberStringFromName(name);
            if (serialNumberString.compare(number) == 0) {
                cout << name << endl;
                foundAnyResult = true;
            }
        }
    }
    if (!foundAnyResult)
        cout << "NONE" << endl;
    return 0;
}
