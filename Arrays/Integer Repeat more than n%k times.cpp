// https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/

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

void findElementsMoreThanNdivKTimes(vector<int> &arr, int k) {
    if (k <= 1) {
        cout << "None" << endl;
        return;
    }

    int n = arr.size();
    unordered_map<int, int> count;  // element, count of element

    for (int i = 0; i < n; i++) {
        if (count.find(arr[i]) != count.end()) {
            count[arr[i]]++;
        } else {
            if (count.size() < k - 1) {  // there can only be max k-1 elements that occur more than n/k times
                count[arr[i]] = 1;
            } else if (count.size() == k - 1) {
                auto it = count.begin();
                while (it != count.end()) {
                    auto temp = it;
                    temp++;
                    it->second--;
                    if (it->second == 0) count.erase(it);
                    it = temp;
                }
            }
        }
    }

    for (auto elem : count) {
        int actualCount = 0;
        for (int i : arr) {
            if (i == elem.first) actualCount++;
        }

        if (actualCount > n / k) {
            cout << elem.first << " has count " << actualCount << endl;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    findElementsMoreThanNdivKTimes(arr, k);

    return 0;
}
