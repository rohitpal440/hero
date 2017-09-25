#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void printArray(const vector<int> &array) {
    for (auto it: array)
        cout << it << " ";
    cout << endl;
}

    // This is Naive Sieve of Eratosthene method
    // Time Complexity: O(nlog(logn))
vector<int> getPrimeNumbersUpto(int n) {
    vector<int> primes;
        // use function<void (void)> instead of auto
    auto updatePrimes = [&primes, n]() {
        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;
        for (long long int i = 0; i*i <= n; i++) {
            if (isPrime[i]) {
                for (auto j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            if (isPrime[i])
                primes.push_back(i);
        }
    };
    updatePrimes();
    return primes;
}

    // This is Modified Sieve of Eratosthene method
    // Time Complexity: O(n)
vector<int> getPrimeNumbers(int n) {
    vector<int> spf(n+1); //smallest prime factor
    vector<int> primes;
    for (int i=2; i<=n; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back (i);
        }
        for (int j = 0; j< (int)primes.size() && primes[j] <= spf[i] && i * primes[j] <= n; ++j)
            spf[i * primes[j]] = primes[j];
    }
    return primes;
}

int main() {
        //    printArray(getPrimeNumbersUpto(100));
        //    printArray(getPrimeNumbers(100));

        // Calculate and compare the time taken
    clock_t t;
    t = clock();
    getPrimeNumbersUpto(100000000);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    cout << "Naive Sieve Eratosthenes \nMethod Time Taken: " << time_taken << " Seconds" << endl;
    t = clock();
    getPrimeNumbers(100000000);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    cout << "Modified Sieve Eratosthenes \nMethod Time Taken: " << time_taken << " Seconds" << endl;
        //    On a dataset of 10^8
        //    Modified Sieve Eratosthenes Method takes Time: 4.38329 Seconds
        //    Naive Sieve Eratosthenes Method takes Time: 5.11097 Seconds
        //
        //    On a dataset of 10^9
        //    Modified Sieve Eratosthenes Method takes Time: 47.8337 Seconds
        //    Naive Sieve Eratosthenes Method takes Time: 57.5822 Seconds
    return 0;
}
