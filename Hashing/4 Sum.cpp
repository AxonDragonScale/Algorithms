// https://www.interviewbit.com/problems/4-sum/
// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all
// unique quadruplets in the array which gives the sum of target. Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order (ie, a ≤ b ≤ c ≤ d). The solution set must not
// contain duplicate quadruplets.

// Another Solution would be to have two nested loops for a(i) and b(j = i+1) and loop using two pointer method for
// c(j+1) and d(n-1). (brackets are starting indices). For i and j loops, skip the element if its same as the previous

vector<vector<int>> Solution::fourSum(vector<int> &arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    map<int, vector<pair<int, int>>> twoSum;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            twoSum[arr[i] + arr[j]].push_back({i, j});  // save all pairs with given sum and then use 2 Sum on it
        }
    }

    set<vector<int>> ans;  // use set to avoid repitition
    for (auto s : twoSum) {
        auto idxAB = s.second;
        if (twoSum.find(k - s.first) != twoSum.end()) {
            auto idxCD = twoSum[k - s.first];

            for (int i = 0; i < idxAB.size(); i++) {
                for (int j = 0; j < idxCD.size(); j++) {
                    if (idxAB[i].second < idxCD[j].first) {
                        vector<int> temp = {arr[idxAB[i].first], arr[idxAB[i].second], arr[idxCD[j].first],
                                            arr[idxCD[j].second]};
                        ans.insert(temp);
                    }
                }
            }
        }
    }

    return vector<vector<int>>(ans.begin(), ans.end());
}

// Solution is based on 2 Sum
// https://www.interviewbit.com/problems/2-sum/

vector<int> Solution::twoSum(const vector<int> &arr, int k) {
    map<int, int> idx;
    for (int i = 0; i < arr.size(); i++) {
        if (idx.find(k - arr[i]) != idx.end()) {
            return {idx[k - arr[i]] + 1, i + 1};
        }

        if (idx.find(arr[i]) == idx.end()) idx[arr[i]] = i;  // dont do this earlier
        // creates a problem if k-arr[i] = arr[i]
    }

    return {};
}
