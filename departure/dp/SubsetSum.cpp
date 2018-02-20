#include <iostream>
#include <vector>

using namespace std;

class SubsetSum {
private:
    const vector<int> set;
    vector< vector<int> > cache;
    void setupCacheForSum(int sum) {
        cache.erase(cache.begin(), cache.end());
        vector< vector<int> > newCache((int)set.size(), vector<int>(sum + 1, 0));
        for (int i = 0; i < set.size(); i++)
            newCache[i][0] = true;
        for (int i = 1; i < newCache[0].size(); i++)
            newCache[0][i] = set[0] == i;
        cache = newCache;
    }
public:
    SubsetSum(const vector<int> &s): set(s) {}
    bool subsetExistsForSum(int sum) {
        if (sum == 0) return true;
        if (cache.size() == 0 || cache[0].size() < sum) {
            setupCacheForSum(sum);
        }
        for (int row = 1; row < set.size(); row++) {
            for (int col = 1; col < cache[row].size(); col++) {
                if (set[row] > col) {
                    cache[row][col] = cache[row - 1][col];
                    continue;
                }
                cache[row][col] = cache[row - 1][col - set[row]];
            }
        }
        return cache[set.size() - 1][sum];
    }
};

int main() {
    vector<int> array = {1, 2, 7, 9};
    SubsetSum s = SubsetSum(array);
    cout << s.subsetExistsForSum(7) << endl;
    cout << s.subsetExistsForSum(6) << endl;
    cout << s.subsetExistsForSum(15) << endl;
    cout << s.subsetExistsForSum(12) << endl;
}
