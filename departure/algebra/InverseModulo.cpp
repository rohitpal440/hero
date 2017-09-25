#include <iostream>
#include <vector>
using namespace std;

int gcdExt(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExt(b % a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return gcd;
}

void printInverseModulo(int a, int m) {
    int x, y;
    int g = gcdExt (a, m, x, y);
    if (g != 1)
        cout << "no solution";
    else {
        x = (x % m + m) % m;
        cout << x << endl;
    }
}

int main() {
    printInverseModulo(3, 11);
}
