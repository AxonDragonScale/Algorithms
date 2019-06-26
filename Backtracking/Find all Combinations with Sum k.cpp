// https://www.interviewbit.com/problems/combination-sum/

// Given a collection of candidate numbers (arr) and a target number (k), find all unique combinations where the
// candidate numbers sums to k. The same repeated number may be chosen from arr unlimited number of times.
// Note:
//     All numbers (including target) will be positive integers.
//     Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//     The combinations themselves must be sorted in ascending order.
//     CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND
//     ai+1 > bi+1) The solution set must not contain duplicate combinations.
// Example: Given candidate set 2,3,6,7 and target 7,
// A solution set is: [2, 2, 3], [7]

void util(vector<vector<int>> &ans, vector<int> &cur, vector<int> &arr, int start, int k) {
    if (k == 0) ans.push_back(cur);
    if (k < 0) return;

    for (int i = start; i < arr.size(); i++) {
        cur.push_back(arr[i]);
        util(ans, cur, arr, i, k - arr[i]);  // not i+1 bcoz repitition is allowed (not start coz non-decreasing)
        cur.pop_back();
    }
}

vector<vector<int>> Solution::combinationSum(vector<int> &arr, int k) {
    vector<vector<int>> ans;
    vector<int> cur;

    sort(arr.begin(), arr.end());
    int i = 0, j = 1;  // Remove duplicates
    while (j < arr.size()) {
        if (arr[i] == arr[j])
            j++;
        else
            arr[++i] = arr[j++];
    }
    arr.resize(i + 1);

    util(ans, cur, arr, 0, k);
    return ans;
}

// https://www.interviewbit.com/problems/combination-sum-ii/

// Given a collection of candidate numbers (arr) and a target number (k), find all unique combinations where the
// candidate numbers sums to k. Each number in arr may only be used once in the combination.
// Note:
//     All numbers (including target) will be positive integers.
//     Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//     The solution set must not contain duplicate combinations.
// Example : Given candidate set 10,1,2,7,6,1,5 and target 8,
// A solution set is: [1, 7], [1, 2, 5], [2, 6], [1, 1, 6]

void util(vector<vector<int>> &ans, vector<int> &cur, vector<int> &arr, int start, int k) {
    if (k == 0) ans.push_back(cur);
    if (k < 0) return;

    for (int i = start; i < arr.size(); i++) {
        cur.push_back(arr[i]);
        util(ans, cur, arr, i + 1, k - arr[i]);
        cur.pop_back();

        while (i + 1 < arr.size() && arr[i] == arr[i + 1]) i++;  // to avoid duplicate sets
    }
}

vector<vector<int>> Solution::combinationSum(vector<int> &arr, int k) {
    vector<vector<int>> ans;
    vector<int> cur;

    sort(arr.begin(), arr.end());

    util(ans, cur, arr, 0, k);
    return ans;
}
