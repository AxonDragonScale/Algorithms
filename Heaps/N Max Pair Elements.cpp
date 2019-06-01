// https://www.interviewbit.com/problems/n-max-pair-combinations/
// Given two arrays A & B of size N each.
// Find the maximum n elements from the sum combinations (A[i] + B[j]) formed from elements in array A and B.

vector<int> Solution::solve(vector<int> &a, vector<int> &b) {
    int n = a.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> ans;
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    set<pair<int, int>> usedSet;

    maxHeap.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});
    usedSet.insert({n - 1, n - 1});

    while (n--) {
        auto e = maxHeap.top();
        maxHeap.pop();
        ans.push_back(e.first);

        int aIdx = e.second.first;
        int bIdx = e.second.second;

        if (aIdx >= 0 && bIdx > 0 && usedSet.find({aIdx, bIdx - 1}) == usedSet.end()) {
            usedSet.insert({aIdx, bIdx - 1});
            maxHeap.push({a[aIdx] + b[bIdx - 1], {aIdx, bIdx - 1}});
        }
        if (aIdx > 0 && bIdx >= 0 && usedSet.find({aIdx - 1, bIdx}) == usedSet.end()) {
            usedSet.insert({aIdx - 1, bIdx});
            maxHeap.push({a[aIdx - 1] + b[bIdx], {aIdx - 1, bIdx}});
        }
    }

    return ans;
}
