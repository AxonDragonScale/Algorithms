// https://www.interviewbit.com/problems/sorted-insert-position/

// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it
// would be if it were inserted in order.

// Basically we have to return index of first element >= k.

int Solution::searchInsert(vector<int> &arr, int k) {
    int n = arr.size();

    int l = 0, r = n - 1;
    while (l <= r) {  // '=' gives extra iteration, so that l can be increased if arr[mid] < k, no effect if >
        int mid = l + (r - l) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] > k)
            r = mid - 1;
        else if (arr[mid] < k)
            l = mid + 1;
    }

    return l;
}

int Solution::searchInsert(vector<int> &arr, int k) {
    int n = arr.size();

    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] > k)
            r = mid - 1;
        else if (arr[mid] < k)
            l = mid + 1;
    }

    if (arr[l] < k) return l + 1;  // l can be need index or one before it
    return l;
}
