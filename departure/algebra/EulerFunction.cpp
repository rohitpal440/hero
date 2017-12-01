    // Euler Function ϕ(n) = No. of number which are relatively prime to n
    // Time Complexity: O(√n)
#include <iostream>
using namespace std;

int ϕ(int n) {
    int result = n;
    for (int i = 2; i*i <= n; i++) {
        if (!(n & 1)) {
            while (!(n & 1))
                n = n/i;
                result = result - result/i;
                }
    }
    if (n > 1)
        result = result - result/n;
        return result;
}

int main() {
    cout << "Relative prime count for number 5: " << ϕ(5) << endl;
}
