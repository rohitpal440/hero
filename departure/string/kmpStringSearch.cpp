#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> getLongestPrefixSuffixArray(const string &s) {
    vector<int> lps(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[j] == s[i]) {
            lps[i] = ++j;
        } else if (j > 0) {
            j = lps[j - 1];
            i--;
        } else {
            lps[i] = 0;
        }
    }
    return lps;
}

pair<bool, int> kmpPatterSearch(const string &pattern, const string &text) {
    auto lps = getLongestPrefixSuffixArray(pattern);
    int i, patternIndex = 0;
    for (i = 0; i < text.size() && patternIndex < pattern.size(); i++) {
        if (text[i] == pattern[patternIndex]) {
            patternIndex++;
        } else if (patternIndex > 0) {
            patternIndex = lps[patternIndex - 1];
            i--;
        }
    }
    if (patternIndex == pattern.size()) {
        return make_pair(true, i - patternIndex);
    }
    return make_pair(false, -1);
}

int main() {
    string text = "abxabcabcaby";//"abcbclgx";
    string pattern = "abcaby";//"bclg";
    auto result = kmpPatterSearch(pattern, text);
    if (result.first) {
        cout << "Pattern Found starting at index: " << result.second << endl;
    } else {
        cout << "No match Found" << endl;
    }
}
