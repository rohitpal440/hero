#include <iostream>
#include <vector>
#include <string>

using namespace std;

class LCS {
private:
    vector< vector<int> > cache;
    void setupCacheFor(string a, string b) {
        cache.erase(cache.begin(), cache.end());
        vector< vector<int> > newCache(a.size() + 1, vector<int>(b.size() + 1, 0));
        cache = newCache;
    }
    string buildLCS(string a, string b) {
        int i = (int)a.size() + 1;
        int j = (int)b.size() + 1;
        vector<char> result;
        while (i > 0 && j >0) {
            if (a[i - 1] == b[j - 1]) {
                result.push_back(a[--i]);
                --j;
            } else if (cache[i][j - 1] > cache[i - 1][j]) {
                j--;
            } else {
                i--;
            }
        }
        string s(result.rbegin(), result.rend());
        return s;
    }

public:
    string getLongestCommonSubSequence(const string a, const string b) {
        setupCacheFor(a, b);
        for (int i = 1; i <= (int)a.size(); i++) {
            for (int j = 1; j <= (int)b.size(); j++) {
                if (a[i - 1] == b[j - 1]) {
                    cache[i][j] = 1 + cache[i - 1][j - 1];
                } else {
                    cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
                }
            }
        }
        return buildLCS(a, b);
    }
};


int main() {
    string a = "ABC";//"ABCDGH";
    string b = "AC";//"AEDFHR";
    LCS object = LCS();
    cout << object.getLongestCommonSubSequence(a, b) << endl;
}
