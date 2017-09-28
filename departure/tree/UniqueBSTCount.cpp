/***
 * Problem:
 * Get possible Binary Search trees count for n distinct node.
 ***/

#include <iostream>
#include <vector>
using namespace std;

class UniqueBstCounter {
    int getUniqueBSTCount(int n, vector<int>& solutions) {
        if (n == 0 || n == 1)
        return 1;
        int uniqueBST = 0;
        for (int i = 0; i < n; i++) {
            if (solutions[i] == INT_MIN)
            solutions[i] = getUniqueBSTCount(i, solutions);
            if (solutions[n - i - 1] == INT_MIN)
            solutions[n - i - 1] = getUniqueBSTCount(n - i - 1, solutions);
            uniqueBST += solutions[i] * solutions[n - i - 1];
        }
        return uniqueBST;
    }
public:
    int getCount(int n) {
        vector<int> solutions(n+1, INT_MIN);
        return getUniqueBSTCount(n, solutions);
    }
};

int main() {
    UniqueBstCounter counter = UniqueBstCounter();
    cout << counter.getCount(3) << endl;
}
