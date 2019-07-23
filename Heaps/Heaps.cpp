// https://www.geeksforgeeks.org/binary-heap/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
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

class MinHeap {
   public:
    vector<int> arr;
    int size;

    MinHeap(int capacity) {
        arr.resize(capacity);
        size = 0;
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void insert(int k) {
        if (size == arr.size()) {
            cout << "Overflow" << endl;
            return;
        }

        arr[size++] = k;  // insert at end

        int i = size - 1;
        while (i != 0 && arr[parent(i)] > arr[i]) {  // reverse this for MaxHeap
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void minHeapify(int i) {
        int l = left(i);
        int r = right(i);

        int smallest = i;
        if (l < size && arr[l] < arr[smallest]) smallest = l;
        if (r < size && arr[r] < arr[smallest]) smallest = r;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    int getMin() { return size > 0 ? arr[0] : INT_MAX; }

    int extractMin() {
        if (size <= 0) return INT_MAX;
        if (size == 1) return arr[--size];

        int min = arr[0];
        arr[0] = arr[size - 1];
        size--;
        minHeapify(0);

        return min;
    }
};