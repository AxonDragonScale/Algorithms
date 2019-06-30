// https://www.geeksforgeeks.org/bucket-sort-2/

#include <algorithm>
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

void bucketSort(vector<float> &arr) {
    int n = arr.size();

    vector<vector<float>> buckets(n);
    for (int i = 0; i < n; i++) {
        buckets[n * arr[i]].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) sort(buckets[i].begin(), buckets[i].end());

    int idx = 0;
    for (auto bucket : buckets) {
        for (float i : bucket) {
            arr[idx++] = i;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<float> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bucketSort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
