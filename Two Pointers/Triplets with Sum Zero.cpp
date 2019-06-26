// https://www.interviewbit.com/problems/3-sum-zero/
// https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/

vector<vector<int>> Solution::threeSum(vector<int> &arr) {
    int n = arr.size();
    set<vector<int>> ans;

    sort(arr.begin(), arr.end());
    for (int k = 0; k < n - 2; k++) {
        int i = k + 1;
        int j = n - 1;
        while (i < j) {
            int s = arr[i] + arr[j] + arr[k];
            if (s == 0) {
                ans.insert({arr[k], arr[i], arr[j]});
                i++;  // dont forget this
                j--;
            } else if (s < 0)
                i++;
            else
                j--;
        }
    }

    return vector<vector<int>>(ans.begin(), ans.end());
}
