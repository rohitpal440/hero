#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getEditDistance(const string &a, const string &b) {
    vector< vector<int> > cache(a.length() + 1, vector<int>(b.length() + 1, 0));
    for (int i = 0; i < a.length(); i++)
        cache[i][0] = i;
    for (int i = 0; i < b.length(); i++)
        cache[0][i] = i;
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1 ] == b[j - 1]) {
                cache[i][j] = cache[i - 1][j - 1];
            } else {
                cache[i][j] = min(cache[i - 1][j - 1], min(cache[i][j - 1], cache[i - 1][j])) + 1;
            }
        }
    }
    return cache[a.length()][b.length()];
}

int main() {
    string a = "kitten";
    string b = "sitting";
    cout << getEditDistance(a, b) << endl;
}
