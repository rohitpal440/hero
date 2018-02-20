#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> &array) {
    for (auto item: array)
        cout << item << " ";
    cout << endl;
}

vector<int> buildLis(const vector<int> &array, const vector<int> &parent, int endIndex) {
    int index = endIndex;
    vector<int> lis;
    while (parent[index] != index) {
        lis.push_back(array[index]);
        index = parent[index];
    }
    lis.push_back(array[index]);
    vector<int> result(lis.rbegin(), lis.rend());
    return result;
}

vector<int> getLongestIncreasingSubSequence(const vector<int> &array) {
    vector<int> temp(array.size(), 1);
    vector<int> parent(array.size());
    for (int i = 0; i < parent.size(); i++)
        parent[i] = i;
    int maxLength = 1;
    int lisEndingIndex = 0;
    for (int i = 1; i < array.size(); i++) {
        for (int j = i - 1 ; j >= 0; j--) {
            if (temp[j] + 1 > temp[i] && array[i] > array[j]) {
                parent[i] = j;
                temp[i] = temp[j] + 1;
            }
            if (maxLength < temp[i]) {
                maxLength = temp[i];
                lisEndingIndex = i;
            }
        }
    }
    return buildLis(array, parent, lisEndingIndex);
}

int main() {
    vector<int> array = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};//{ 10, 22, 9, 33, 21, 50, 41, 60, 80 };
    printArray(getLongestIncreasingSubSequence(array));
    return 0;
}
