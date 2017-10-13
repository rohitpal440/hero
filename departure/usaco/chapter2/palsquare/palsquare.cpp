/*
 ID: rohitpa4
 PROG: palsquare
 LANG: C++11
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

string getNumberInBase(int number, int base = 10) {
    string numberInBase;
    while (number) {
        int q = (int) number / base;
        int remainder = number % base;
        number = q;
        char remainderChar;
        if (remainder > 9) {
            remainderChar = 65 + remainder - 10;
        } else {
            remainderChar =  48 + remainder;
        }
        numberInBase += remainderChar;
    }
    reverse(numberInBase.begin(), numberInBase.end());
    return numberInBase;
}

bool isPallindrom(string number) {
    for (int i = 0; i < number.size() / 2; i++) {
        if (number[i] != number[number.size() - 1 - i])
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    freopen("palsquare.in", "r", stdin);
    freopen ("palsquare.out","w",stdout);
    int base;
    cin >> base;
    for (int i = 1; i <= 300; i++) {
        string squaredNumberString = getNumberInBase(i * i, base);
        if (isPallindrom(squaredNumberString)) {
            cout << getNumberInBase(i, base) <<  " " << squaredNumberString << endl;
        }
    }
    return 0;
}
