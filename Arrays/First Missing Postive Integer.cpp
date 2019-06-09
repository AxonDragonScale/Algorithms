// https://www.interviewbit.com/problems/first-missing-integer/
// https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/  -> TODO
// https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array-set-2/  -> TODO

int Solution::firstMissingPositive(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] <= n) {
            int pos = arr[i] - 1;
            if (arr[pos] != arr[i]) {
                swap(arr[pos], arr[i]);
                i--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) return i + 1;
    }
    return n + 1;
}
