// nth fibonacci number
// let F(n) is nth fibbonacci number
// let matrix p = {
//    0, 1
//    1, 1
//   }
// then
//  p^n = {
//    F(n+1) F(n)
//    F(n)   F(n-1)
//   }

#include <iostream>
using namespace std;

void multiplyMatrix(int F[2][2], int M[2][2]) {
    int w = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int x = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int y = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int z = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = w;
    F[0][1] = x;
    F[1][0] = y;
    F[1][1] = z;
}

void binPow(int F[2][2], int n) {
    if (n == 0 || n == 1) return;
    int M[2][2] = {
        {0,1},
        {1,1}
    };
    binPow(F, n/2);
    multiplyMatrix(F, F);
    if (n & 1)
        multiplyMatrix(F, M);
}

int nthFibonacci(int n) { //where n >= 0
    if (n == 0 || n < 0) return 0;
    int F[2][2] = {
        {0,1},
        {1,1}
    };
    binPow(F, n);
    return F[1][0];
}

int main() {
    cout << nthFibonacci(10) << endl;
    return 0;
}
