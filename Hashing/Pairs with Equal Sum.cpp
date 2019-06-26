// https://www.interviewbit.com/problems/equal/

#define ff first
#define ss second

vector<int> Solution::equal(vector<int> &arr) {
    int n = arr.size();

    vector<int> ans;
    map<int, pair<int, int>> sums;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];

            if (sums.find(sum) == sums.end()) {
                sums[sum] = {i, j};
            } else {
                pair<int, int> p = sums[sum];
                if (p.ff == i || p.ff == j || p.ss == i || p.ss == j) continue;
                vector<int> temp = {p.ff, p.ss, i, j};
                if (ans.empty() || temp < ans) ans = temp;
            }
        }
    }

    return ans;
}
