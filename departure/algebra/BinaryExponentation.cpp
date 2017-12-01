// Binary Exponentation: a^n
#include <iostream>
using namespace std;

// recursive version
long long binPow(int a, int n) {
    if (a == 0)
        return 0;
    if (a == 1 || n == 0)
        return 1;
    if (n & 1) // if n is odd
        return a * binPow(a, n - 1);
    long long result = binPow(a, n / 2);
    return result * result;
}

// iterative approach
long long binPowIterative(int a, int n) {
    if (a == 0) return 0;
    if (a == 1 || n == 0)
        return 1;
    long long result = 1;
    while (n) {
            //        if (n & 1) {
            //            result = a * result;
            //            n--;
            //        } else {
            //            a = a * a;
            //            n = n >> 1;
            //        }
            // simplified version of above commented code
        if (n & 1)
            result = a * result;
        a = a * a;
        n = n >> 1;
    }
    return result;
}
int main() {
    cout << "10^6: " << binPow(10, 6) << endl;
    cout << "10^6: " << binPowIterative(10, 6) << endl;
    return 0;
}
