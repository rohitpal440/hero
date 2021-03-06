/***
 * Given an array of numbers, arrange them in a way that yields the largest
 * value. For example, if the given numbers are {54, 546, 548, 60}, the
 * arrangement 6054854654 gives the largest value. And if the given number
 * are {1, 34, 3, 98, 9, 76, 45, 4}, then the arrangement 998764543431
 * gives the largest value.
 ***/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string getLargestNumber(const vector<int> &array) {
    vector<string> stringArray(array.size());
    for(int i = 0; i < array.size(); i++)
        stringArray[i] = to_string(array[i]);
    stable_sort(stringArray.begin(), stringArray.end(), [](string a, string b) {
        string temp = a;
        a.reserve(a.size() + b.size());
        b.reserve(a.size() + b.size());
        a = a.append(b);
        b = b.append(temp);
        return a.compare(b) > 0 ? true : false;
    });
    string str;
    string zero = "0";
    int startIndex = 0;
    if (stringArray[0].compare(zero) == 0) {
        for ( int i = 1; i < stringArray.size(); i++) {
            startIndex = i;
            if (stringArray[0].compare(zero) != 0)
                break;
        }
    }
    for(int i = startIndex; i < stringArray.size(); i++)
        str.append(stringArray[i]);
    return str;
}

int main() {
    vector<int> array = {1,2,3,4,5,6,7,8,9,90,40,0}; //{0,0,0,0};
    cout << getLargestNumber(array) << endl;
    return 0;
}

