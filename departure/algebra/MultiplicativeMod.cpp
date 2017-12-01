// MultiplicativeMod: (a.b) mod m for large number
// using Russian Peasant Algorithm

#include <iostream>
using namespace std;

long long multiplicativeMod(long long a, long long b, long long m) {
    if (a == 0) return 0;
    if (a == 1)
        return b % m;
    long long result = 0;
    a = a % m;
    while (b) {
        if (b & 1)
            result = (result + a) % m;
        a = (a << 1) % m;
        b = b >> 1;
    }
    return result % m;
}
int main() {
    cout << "MultiplicativeMod of 17 * 58 mod 7 : "
    << multiplicativeMod(17, 58, 7) << endl;
    return 0;
}
