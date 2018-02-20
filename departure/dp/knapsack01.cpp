#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
};

void printItems(const vector<Item> &items) {
    for (auto item: items)
        cout << "{" << item.weight << "," << item.value << "}" << endl;
}

class Knapsack01 {
    vector< vector<int> > cache;
    void setupCache(const vector<Item> &items, int capacity) {
        cache.erase(cache.begin(), cache.end());
        vector< vector<int> > newCache(items.size() + 1, vector<int> (capacity + 1, 0));
        cache = newCache;
    }

    vector<Item> fillKnapsack(const vector<Item> &items, int capacity) {
        int i = (int)items.size();
        int j = capacity;
        vector<Item> selectedItems;
        while (i > 0 && j > 0) {
            if (cache[i][j] > cache[i-1][j]) {
                selectedItems.push_back(items[i-1]);
                j = j - items[i-1].weight;
                i--;
            } else {
                i--;
            }
        }
        reverse(selectedItems.begin(), selectedItems.end());
        return selectedItems;
    }
public:
    vector<Item> getItemInKnapSack(int capacity, const vector<Item> &items) {
        setupCache(items, capacity);
        for (int i = 1; i <= items.size(); i++) {
            for (int j = 1; j <= capacity; j++) {
                if (j < items[i - 1].weight) {
                    cache[i][j] = cache[i-1][j];
                } else {
                    cache[i][j] = max(items[i-1].value + cache[i - 1][j - items[i-1].weight], cache[i - 1][j]);
                }
            }
        }
        return fillKnapsack(items, capacity);
    }
};

vector<Item> getItems(const vector<int> &weight, const vector<int> &value) {
    vector<Item> result;
    for (int i = 0; i < weight.size(); i++) {
        result.push_back({weight[i], value[i]});
    }
    return result;
}

int main() {
    vector<int> weight = {5, 4, 2, 3};//{1, 3, 4, 5};
    vector<int> value = {10, 40, 30 , 50};//{1, 4, 5, 7};
    Knapsack01 object = Knapsack01();
    printItems(object.getItemInKnapSack(7, getItems(weight, value)));
}
