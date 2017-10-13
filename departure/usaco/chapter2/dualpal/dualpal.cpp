/*
 ID: rohitpa4
 PROG: dualpal
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
            remainderChar = 65 + remainder - 9;
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
    freopen("dualpal.in", "r", stdin);
    freopen ("dualpal.out","w",stdout);
    int n, s;
    cin >> n >> s;
    for (int i = s + 1; i <= 2147483647 && n > 0; i++) {
        int count = 0;
        for (int base = 2; base <= 10; base++) {
            if (isPallindrom(getNumberInBase(i, base)))
                count++;
            if (count >= 2) {
                n--;
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
