/*
 ID: rohitpa4
 PROG: transform
 LANG: C++11
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool equalTo(const vector<string> matrixA, const vector<string> matrixB) {
    if (matrixA.size() != matrixB.size()) {
        return false;
    }
    for (int i = 0; i < matrixA.size(); i++) {
        if (matrixA[i].compare(matrixB[i]))
            return false;
    }
    return true;
}

vector<string> rotateBy90Degree(const vector< string > &matrix) {
    int n = matrix[0].size();
    vector<string> rotatedMatrix(matrix);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotatedMatrix[i][j] = matrix[n - 1 - j][i];
        }
    }
    return rotatedMatrix;
}

vector <string> rotateBy180Degree(const vector<string> &matrix) {
    return rotateBy90Degree(rotateBy90Degree(matrix));
}

vector<string> rotateBy270Degree(const vector<string> &matrix) {
    return rotateBy90Degree(rotateBy180Degree(matrix));
}

vector<string> reflectByYAxix(const vector< string > &matrix) {
    int n = matrix[0].size();
    vector<string> reflectedMatrix(matrix);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            reflectedMatrix[i][j] = matrix[i][n - 1 - j];
        }
    }
    return reflectedMatrix;
}

bool compositeTransform(const vector<string> &originalMatrix, const vector<string> &tranformedMatrix) {
    auto reflectedMatrix = reflectByYAxix(originalMatrix);
    return equalTo(rotateBy90Degree(reflectedMatrix), tranformedMatrix)
    || equalTo(rotateBy180Degree(reflectedMatrix), tranformedMatrix)
    || equalTo(rotateBy270Degree(reflectedMatrix), tranformedMatrix);
}

int main(int argc, const char * argv[]) {
    freopen("transform.in", "r", stdin);
    freopen ("transform.out","w",stdout);
    int n;
    cin >> n;
    vector<string> originalPattern(n), transformedPattern(n);
        // get original pattern
    for(int i = 0; i < n; i++) {
        cin >> originalPattern[i];
    }
        // get target pattern
    for (int i = 0; i < n; i++) {
        cin >> transformedPattern[i];
    }

    if (equalTo(rotateBy90Degree(originalPattern), transformedPattern)) {
        cout << 1 << endl;
    } else if (equalTo(rotateBy180Degree(originalPattern), transformedPattern)) {
        cout << 2 << endl;
    } else if (equalTo(rotateBy270Degree(originalPattern), transformedPattern)) {
        cout << 3 << endl;
    } else if (equalTo(reflectByYAxix(originalPattern), transformedPattern)) {
        cout << 4 << endl;
    } else if (compositeTransform(originalPattern, transformedPattern)) {
        cout << 5 << endl;
    } else if (equalTo(originalPattern, transformedPattern)) {
        cout << 6 << endl;
    } else {
        cout << 7 << endl;
    }
    return 0;
}
