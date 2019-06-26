// https://www.interviewbit.com/problems/combinations/

void util(int n, int k, int start, vector<vector<int>> &ans, vector<int> &cur) {
    if (cur.size() == k) {
        ans.push_back(cur);
        return;
    }

    for (int i = start; i <= n - k + start && i <= n; i++) {
        cur.push_back(i);
        util(n, k, i + 1, ans, cur);
        cur.pop_back();
    }
}

vector<vector<int>> Solution::combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> cur;

    util(n, k, 1, ans, cur);
    return ans;
}
