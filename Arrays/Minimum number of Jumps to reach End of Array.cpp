
// https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/		   -> O(n) solution
// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
// https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/    -> DP O(n^2) solution - bad

// https://www.interviewbit.com/problems/min-jumps-array/

int Solution::jump(vector<int> &arr) {
    int n = arr.size();
    if (n == 1) return 0;

    int maxReach = arr[0], jumps = 1, stepsRemaining = arr[0];
    for (int i = 1; i < n - 1; i++) {
        if (stepsRemaining <= 0) return -1;
        maxReach = max(maxReach, i + arr[i]);
        stepsRemaining--;

        if (stepsRemaining == 0) {
            // when stepsRemaining becomes 0, we would have made a jump (to the location which gave us maxReach)
            jumps++;
            stepsRemaining = maxReach - i;  // if maxReach is <= i, we return -1 in next interation
        }
    }

    if (stepsRemaining <= 0) return -1;
    return jumps;
}

int Solution::jump(vector<int> &arr) {
    int n = arr.size();

    vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0;  // already where we need to be

    for (int i = n - 2; i >= 0; i--) {
        int jump = arr[i];
        for (int j = i + 1; j <= i + jump; j++) {  // find min from all locations we can jump to
            dp[i] = min(dp[i], dp[j]);
        }
        if (dp[i] != INT_MAX) dp[i] += 1;  // + 1 for jumping to location with min
    }

    if (dp[0] == INT_MAX) return -1;
    return dp[0];
}

// Ignore
#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

#define LN cout << __LINE__ << endl
#define iPair pair<int, int>
#define ff first
#define ss second

using namespace std;

int t, n, maxReach, cnt, stepsRemaining;
int arr[100];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (arr[0] == 0) {
            cout << -1 << endl;
            continue;
        }

        maxReach = arr[0];
        cnt = 1;
        stepsRemaining = arr[0];

        for (int i = 1; i < n; i++) {
            if (i == n - 1) {  // when we reach the end
                cout << cnt << endl;
                break;
            }

            maxReach = max(maxReach, i + arr[i]);
            stepsRemaining -= 1;

            if (stepsRemaining == 0) {
                cnt++;
                // if we exhausted all stepsRemaining, we must have taken
                // taken a jump in one of them (the one that gets us maxReach)

                if (i >= maxReach) {
                    // if current index or any previous index is greater than
                    // maxReach we cant go forward
                    cout << -1 << endl;
                    break;
                }
                stepsRemaining = maxReach - i;
            }
        }
    }

    return 0;
}