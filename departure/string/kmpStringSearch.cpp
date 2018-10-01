// KMP String search algorithm
// Algorithm to find the pattern in a string

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Create an array which contains the size of suffix which is also prefix
// of the string which ends at that index
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
    vector<int> startingIndexMatches;
    for (i = 0; i < text.size() && patternIndex < pattern.size(); i++) {
        if (text[i] == pattern[patternIndex]) {
            patternIndex++;
            if (patternIndex == pattern.size()) { // to find multiple occurrence
                startingIndexMatches.push_back(i - patternIndex + 1);
                cout << "Found pattern at index: " << i - patternIndex + 1 << endl;
                cout << text.substr(i - patternIndex + 1, pattern.size()) << endl;
                patternIndex = lps[--patternIndex];
                i--;
            }
        } else if (patternIndex > 0 && patternIndex < pattern.size()) {
            patternIndex = lps[patternIndex - 1];
            i--;
        }
    }
    if (!startingIndexMatches.empty()) {
        return make_pair(true, startingIndexMatches.front());
    }
    return make_pair(false, -1);
}

int main() {
    string text = "abxabcabcabyababcaby";//"abcbclgx";
    string pattern = "abcaby";//"bclg";
    auto result = kmpPatterSearch(pattern, text);
    if (result.first) {
        cout << "Pattern Found starting at index: " << result.second << endl;
    } else {
        cout << "No match Found" << endl;
    }
}
