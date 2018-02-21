#include <iostream>
#include <vector>

using namespace std;

int waysToChange(int amount, const vector<int> &coins) {
    vector< vector<int> > cache (coins.size(), vector<int>(amount + 1, 0));
    for (int i = 0; i < coins.size(); i++)
        cache[i][0] = 1;
    for (int i = 0; i < coins.size(); i++) {
        for (int j = 1; j <= amount; j++) {
            if (j < coins[i]) {
                cache[i][j] = (i > 0 ? cache[i-1][j] : 0);
            } else {
                cache[i][j] = (i > 0 ? cache[i-1][j] : 0) + (j - coins[i] >= 0 ? cache[i][j - coins[i]] : 0);
            }
        }
    }
    return cache[coins.size() - 1][amount];
}

int main() {
    vector<int> coins = {2,5,3,6};
    cout << waysToChange(10, coins) << endl;
}
