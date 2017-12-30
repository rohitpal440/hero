#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Key {
    int n;
    int max_digits;
    bool operator==(const Key &other) const {
        return this->n == other.n && this->max_digits == other.max_digits;
    }
};

namespace std {
    template<>
    struct hash<Key> {
        std::size_t operator()(const Key& key) const {
            using std::size_t;
            using std::hash;
            size_t result = 17;
            result = result * 31 + hash<int>()(key.n);
            result = result * 31 + (hash<int>()(key.max_digits) << 1);
            return result >> 1;
        }
    };
}

size_t integerPartitionUtils(int n, int max_digits, unordered_map<Key, size_t> &cache) {
    if (n <= 1 || max_digits == 1)
        return 1;
    if (max_digits > n)
        max_digits = n;
    auto alreadyFound = cache.find({n, max_digits});
    if (alreadyFound != cache.end())
        return alreadyFound->second;
    int result = 0;
    for (int i = max_digits; i >= 1; i--)
        result += integerPartitionUtils(n - i, i, cache);
    cache[{n, max_digits}] = result;
    return result;
}

size_t integerPartition(int n) {
    unordered_map<Key, size_t> cache;
    return integerPartitionUtils(n, n, cache);
}

int main() {
    cout << integerPartition(1150) << endl;
}
