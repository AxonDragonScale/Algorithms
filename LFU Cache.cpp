// https://leetcode.com/problems/lfu-cache/discuss/94516/Concise-C%2B%2B-O(1)-solution-using-3-hash-maps-with-explanation

// The main idea is to put all keys with the same frequency to a linked list so the most recent one can be evicted

class LFUCache {
    int cap;
    int size;
    int minFreq;
    unordered_map<int, pair<int, int>> m;           // key to {value,freq};
    unordered_map<int, list<int>::iterator> mIter;  // key to list iterator;
    unordered_map<int, list<int>> fm;               // freq to key list;

   public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
        minFreq = 0;
    }

    int get(int key) {
        if (m.count(key) == 0) return -1;  // if not found

        fm[m[key].second].erase(mIter[key]);
        m[key].second++;
        fm[m[key].second].push_front(key);
        mIter[key] = fm[m[key].second].begin();

        if (fm[minFreq].size() == 0) minFreq++;

        return m[key].first;
    }

    void set(int key, int value) {
        if (cap <= 0) return;

        int storedValue = get(key);
        if (storedValue != -1) {
            m[key].first = value;
            return;
        }

        if (size >= cap) {
            m.erase(fm[minFreq].back());
            mIter.erase(fm[minFreq].back());
            fm[minFreq].pop_back();
            size--;
        }

        m[key] = {value, 1};
        fm[1].push_front(key);
        mIter[key] = fm[1].begin();
        minFreq = 1;
        size++;
    }
};