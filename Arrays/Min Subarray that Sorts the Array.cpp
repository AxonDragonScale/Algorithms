// https://www.interviewbit.com/problems/maximum-unsorted-subarray/

// Given an array find the smallest subarray on sorting which the whole array becomes sorted

vector<int> Solution::subUnsort(vector<int> &arr) {
    int n = arr.size();

    int i = 0, j = n - 1;
    while (i < n - 1 && arr[i] <= arr[i + 1]) i++;  // 1st element thats smaller than previous
    while (j > 0 && arr[j] >= arr[j - 1]) j--;      // last element thats larger then next
    // The subarray will be atleast from [i..j]

    if (i == n - 1) return {-1};

    // Find min and max in arr[i..j]
    int mn = arr[i], mx = arr[i];
    for (int k = i; k <= j; k++) {
        mn = min(mn, arr[k]);
        mx = max(mx, arr[k]);
    }

    int l = 0, r = n - 1;
    while (arr[l] <= mn) l++;  // 1st element greater than min (min should be before this, so its in subarray)
    while (arr[r] >= mx) r--;  // last element lesser than max (max should be after this, so its in subarray)

    return {l, r};
}
