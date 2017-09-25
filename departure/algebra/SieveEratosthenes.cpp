
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
    // Source: GeeksForGeeks
vector<int> getPrimeNumbers(int n) {
    vector<int> isPrime(n+1, true);
    vector<int> spf(n+1); //smallest prime factor
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 0; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            spf[i] = i;
        }
        for (int j = 0; j < primes.size()
             && i * primes[j] <= n
             && primes[j] <= spf[i]; j++) {
            isPrime[i * primes[j]] = false;
            spf[i * primes[j]] = primes[j];
        }
    }
    return primes;
}

int main() {
        //    printArray();
        //    printArray(getPrimeNumbers(10000));
        // Calculate and compare the time taken
    clock_t t;
    t = clock();
    getPrimeNumbersUpto(1000000000);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    cout << "Naive Sieve Eratosthenes Method Time Taken: " << time_taken << " Seconds" << endl;
    t = clock();
    getPrimeNumbers(1000000000);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    cout << "Modified Sieve Eratosthenes Method Time Taken: " << time_taken << " Seconds" << endl;
        //    On a dataset of 10^8
        //    Modified Sieve Eratosthenes Method takes Time: 7.26184 Seconds
        //    Naive Sieve Eratosthenes Method takes Time: 4.92235 Seconds
        //
        //    On a dataset of 10^9
        //    Modified Sieve Eratosthenes Method takes Time: 551.991 Seconds
        //    Naive Sieve Eratosthenes Method takes Time: 58.0304 Seconds
    return 0;
}
