// https://www.interviewbit.com/problems/3-sum/

int Solution::threeSumClosest(vector<int> &arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int i, j, ans, diff = INT_MAX;
    for (int t = 0; t < n - 2; t++) {
        i = t + 1;
        j = n - 1;
        while (i < j) {
            int s = (arr[i] + arr[j] + arr[t]);
            if (s < k) {
                i++;
            } else {
                j--;
            }

            if (abs(k - s) < diff) {
                ans = s;
                diff = abs(k - ans);
            }
        }
    }

    return ans;
}
