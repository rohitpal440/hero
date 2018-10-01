#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printArray(const vector<int> &array) {
    for (auto it : array)
        cout << it << " ";
    cout << endl;
}

string getStuffedString(const string &originalString) {
    char stuffedString[originalString.size() * 2 + 1];
    stuffedString[0] = '#';
    for (int i = 0; i < originalString.size(); i++) {
        stuffedString[2 * i + 1] = originalString[i];
        stuffedString[2 * i + 2] = '#';
    }
    return string(stuffedString);
}

pair<string, pair<int, int> > getSubPallindrom(const string &originalString) {
    auto s = getStuffedString(originalString);
    vector<int> p(originalString.size() * 2 + 1, 0);
    int center = 0, right = -1, radius;
    int largestPallindromCenter = 0;
    int maxRadius = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i <= right) {
            radius = min(p[2 * center - i], right - i);
        } else {
            radius = 0; // could be 1
        }
        while(i + radius < s.size() && i - radius >= 0 && s[i - radius] == s[i + radius])
            radius++;
        p[i] = radius;
        if (i + radius - 1 > right) {
            center = i;
            right = i + radius - 1;
        }
        if (maxRadius < p[i]) {
            maxRadius = p[i];
            largestPallindromCenter = i;
        }
    }
    int begin = (largestPallindromCenter + 1 - maxRadius) / 2;
    int end = (largestPallindromCenter - 1 + maxRadius) / 2;
    string largestSubPalindrom = originalString.substr(begin, end - begin);
    return make_pair(largestSubPalindrom, make_pair(begin, end - 1));
}


int main() {
    string s = "abaxabaxabb";
    auto result = getSubPallindrom(s);
    cout << "Largest Sub-Pallindrom: " << result.first << endl;
    cout << "Size: " << result.first.size() << endl;
    cout << "Index: " << result.second.first << " to " << result.second.second << endl;
    return 0;
}
