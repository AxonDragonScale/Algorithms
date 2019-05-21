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
    unordered_map<int, int> data_map;                  // key, value - key is identifier of the data
    list<int> lru_list;                                // key
    unordered_map<int, list<int>::iterator> list_map;  // key, iterator
    int capacity;

   public:
    Cache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (data_map.find(key) == data_map.end()) {
            return -1;  // key not found
        }

        justUsed(key);
        return data_map[key];
    }

    void put(int key, int value) {
        if (data_map.find(key) == data_map.end()) {  // Key doesnt exist in cache
            data_map[key] = value;
            lru_list.push_front(key);
            list_map[key] = lru_list.begin();

            if (lru_list.size() > capacity) {
                int key = lru_list.back();
                lru_list.pop_back();
                data_map.erase(key);
                list_map.erase(key);
            }
        } else {
            data_map[key] = value;
            justUsed(key);
        }
    }

    void justUsed(int key) {
        list<int>::iterator it = list_map[key];
        lru_list.erase(it);
        lru_list.push_front(key);
        list_map[key] = lru_list.begin();
    }
};

int main() {
    // the code

    return 0;
}
