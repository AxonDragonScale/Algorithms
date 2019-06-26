#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define LN cout << __LINE__ << endl
#define ff first
#define ss second

using namespace std;

using iPair = pair<int, int>;
using vi = vector<int>;
using di = deque<int>;
using lli = long long int;

class Cache {
   private:
    unordered_map<int, int> cache;                     // key, value - key is identifier of the data
    list<int> lruList;                                 // keys - front will be Most recently used, and back is lru
    unordered_map<int, list<int>::iterator> listIter;  // key, iterator
    int capacity;

   public:
    Cache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            auto it = listIter[key];  // remove key from list and add it to front
            lruList.erase(it);
            lruList.push_front(key);
            listIter[key] = lruList.begin();
            return cache[key];
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {  // key already exists (just update and put it in front of lruList)
            auto it = listIter[key];
            lruList.erase(it);
        }

        cache[key] = value;
        lruList.push_front(key);
        listIter[key] = lruList.begin();

        if (cache.size() > capacity) {
            int lruKey = lruList.back();
            lruList.pop_back();
            listIter.erase(lruKey);
            cache.erase(lruKey);
        }
    }
};

int main() {
    // the code

    return 0;
}
