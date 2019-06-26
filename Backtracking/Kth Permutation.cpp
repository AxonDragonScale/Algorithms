// https://www.interviewbit.com/problems/kth-permutation-sequence/

// For a given n, return the kth permutation of the numbers [1..n]

int fac(int n) {
    if (n > 12) return INT_MAX;

    int res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

string util(vector<int> &arr, int k) {
    int n = arr.size();
    if (n == 0) return "";
    if (k > fac(n)) return "";

    int f = fac(n - 1);
    int pos = k / f;
    k = k % f;

    string s = to_string(arr[pos]);  // string coz n can be multi-digit
    arr.erase(arr.begin() + pos);
    return s + util(arr, k);
}

string Solution::getPermutation(int n, int k) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    return util(arr, k - 1);  // k-1 coz % is 0 based, so we start permutations from 0 not 1
}
