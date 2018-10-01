// Z-Algorithm
// Longest substring starting at index k which is also a prefix of string

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printArray(const vector<int> array) {
    for (auto it: array)
        cout << it << " ";
    cout << endl;
}

vector<int> zFunction(const string &s) {
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i]);
        while ( i + z[i] < n && s[i + z[i]] == s[z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

// Another way to calculate Z values
vector<int> z_Function(const string &s) {
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i > r) { // if i outside right boundary reset boundaries
            l = r = i;
            while (r < n && s[r] == s[r - l]) // extend right boundary if match
                r++;
            z[i] = r - l; // store length of substring starting at i which is also prefix 
            r--;
        } else {
            int k = i - l;
            if (z[k] < r - i + 1) { // if value at z[k] does not go beyond right boundary
                z[i] = z[k];
            } else { //otherwise reset left boundary
                l = i;
                while (r < n && s[r] == s[r - l]) // repeat steps to extend right boundary
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}

int main() {
    string s = "aaaaa";
    printArray(zFunction(s));
    printArray(z_Function(s));
}
