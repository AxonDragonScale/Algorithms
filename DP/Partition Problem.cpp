
// TODO: Check this.

// Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both
// subsets is same or not.
// https://www.geeksforgeeks.org/partition-problem-dp-18/
// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

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

int main() {
    int n, sum;
    cin >> n;

    deque<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if (sum % 2 != 0) {
        cout << "Can't be partitioned.";
    } else {
        deque<deque<bool> > partition(n + 1, deque<bool>(sum / 2 + 1));
        // partition[i][j] represents a subset of arr[0..i] has a sum j or not

        // Each subset has a sum 0
        for (int i = 0; i <= n; i++) {
            partition[i][0] = true;
        }

        // No empty subset can have a non-zero sum
        for (int j = 1; j <= sum / 2; j++) {
            partition[0][j] = false;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum / 2; j++) {
                if (arr[i] > j) {
                    partition[i][j] = partition[i - 1][j];
                } else {
                    partition[i][j] = partition[i - 1][j] || partition[i - 1][j - arr[i]];
                }
            }
        }

        if (partition[n][sum / 2]) {
            cout << "Partition exists" << endl;
        } else {
            cout << "Partition doesn't exist." << endl;
        }
    }

    return 0;
}
