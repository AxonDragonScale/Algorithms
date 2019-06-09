// https://www.interviewbit.com/problems/max-distance/
// https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/ -> solution

int Solution::maximumGap(const vector<int> &arr) {
    int n = arr.size();

    vector<int> minLeft(n), maxRight(n);
    //  minLeft[i] holds the smallest element on left side of arr[i] including arr[i]
    // maxRight[j] holds the greatest element on right side of arr[j] including arr[j]
    minLeft[0] = arr[0];
    maxRight[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++) {
        minLeft[i] = min(arr[i], minLeft[i - 1]);
    }

    for (int j = n - 2; j >= 0; j--) {
        maxRight[j] = max(arr[j], maxRight[j + 1]);
    }

    int ans = -1;
    int i = 0, j = 0;
    while (i < n && j < n) {  // iterate from left to right
        if (minLeft[i] <= maxRight[j]) {
            // If minLeft[i] <= maxRight[j], distance will be atleast j-i, lower i are already covered, so we just have
            // to cover greater j
            ans = max(ans, j - i);
            j++;
        } else {
            i++;
        }
    }

    return ans;
}
