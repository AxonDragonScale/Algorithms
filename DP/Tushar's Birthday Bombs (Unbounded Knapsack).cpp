// https://www.interviewbit.com/problems/tushars-birthday-bombs/
// https://cs.stackexchange.com/questions/96984/find-the-lexicographically-smallest-order-of-n-numbers-such-that-the-total-of-n

vector<int> Solution::solve(int r, vector<int> &s) {
    int n = s.size();
    vector<int> ans;

    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] < s[minIdx]) minIdx = i;
    }

    int maxKicks = r / s[minIdx];
    if (maxKicks == 0) return ans;
    for (int i = 0; i < maxKicks; i++) {
        ans.push_back(minIdx);
    }

    int sum = maxKicks * s[minIdx];
    int temp = maxKicks, idx = 0;
    for (int i = 0; i < minIdx; i++) {  // we can get lexicographically smaller answer only before minIdx
        if (sum == r || temp == 0) return ans;

        while (sum - s[minIdx] + s[i] <= r && idx < maxKicks) {
            ans[idx++] = i;
            sum += s[i] - s[minIdx];
        }
    }

    return ans;
}
