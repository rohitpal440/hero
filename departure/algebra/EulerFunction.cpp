    // Euler Function ϕ(n) = No. of number which are relatively prime to n
    // ϕ(p^a) = p^a - p^(a - 1) // where p is prime and a is natural number
    // ϕ(ab) = ϕ(a).ϕ(b)
    // n = p1^a1 . p2^a2 . p3^a3.....pk^ak
    // using above equations we can drive
    // ϕ(n) = n.(1 - 1/p1).(1 - 1/p2).....(1 - 1/pk)
    // Time Complexity: O(√n)
#include <iostream>
using namespace std;

int ϕ(int n) {
    int result = n;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n = n/i;
            result = result - result/i; // similar to result *= 1.0 - 1.0/i
        }
    }
    if (n > 1)
        result = result - result/n;
    return result;
}

int main() {
    cout << "Relative prime count for number 5: " << ϕ(5) << endl;
}
