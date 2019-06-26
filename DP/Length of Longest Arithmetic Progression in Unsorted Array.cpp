// https://www.interviewbit.com/problems/longest-arithmetic-progression/

int Solution::solve(const vector<int> &arr) {
    int n = arr.size();
    if (n <= 2) return n;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    // dp[i][j] is length of AP with arr[i] and arr[j] as last two elements
    unordered_map<int, int> idx;  // store indices of elements to left of i

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long int need = 2 * arr[i] - arr[j];  // need is the element before i, arr[i] - need = arr[j] - arr[i]

            dp[i][j] = 2;
            if (idx.find(need) != idx.end()) {
                int pos = idx[need];        // pos is before i
                dp[i][j] = dp[pos][i] + 1;  // same as adding j to AP with pos and i as last two elements
            }

            ans = max(ans, dp[i][j]);
        }

        idx[arr[i]] = i;  // we only need rightmost occurence, so overwriting is fine
    }

    return ans;
}

// int Solution::solve(const vector<int> &arr) {
//     int n = arr.size();

//     if(n <= 2) return n;

//     int maxLen = 0;
//     for(int i = 0; i<n; i++) {
//         for(int j = i+1; j<n; j++) {
//             int curLen = 2;
//             int last = arr[j];
//             int diff = arr[j] - arr[i];

//             for(int k = j+1; k<n; k++) {
//                 if(arr[k] - last == diff) {
//                     curLen++;
//                     last = arr[k];
//                 }
//             }

//             maxLen = max(curLen, maxLen);
//         }
//     }

//     return maxLen;
// }
