// https://www.interviewbit.com/problems/max-continuous-series-of-1s/

// You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips
// allowed. Find the position of zeros which when flipped will produce maximum continuous series of 1s.
// For this problem, return an array of indices of maximum continuous series of 1s in order.

vector<int> Solution::maxone(vector<int> &arr, int k) {
    int n = arr.size();

    int start = 0, end = 0, j = 0, mx = 0, cur = 0, flips = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            cur++;
        } else {
            flips++;
            cur++;
            if (flips > k) {
                while (arr[j] != 0) {
                    j++;
                    cur--;
                }
                j++;
                cur--;
                flips--;
            }
        }

        if (mx < cur) {
            mx = cur;
            start = j;
            end = i;
        }
    }

    vector<int> ans;
    for (int i = start; i <= end; i++) {
        ans.push_back(i);
    }
    return ans;
}
