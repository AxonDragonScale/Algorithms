// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

// You are given a read only array of n integers from 1 to n.
// Each integer appears exactly once except A which appears twice and B which is missing.
// Return A and B.

vector<int> Solution::repeatedNumber(const vector<int> &arr) {
    long long int AminusB = 0;
    long long int A2minusB2 = 0;

    for (int i = 0; i < arr.size(); i++) {
        AminusB += (long long)arr[i] - (long long)(i + 1);
        A2minusB2 += ((long long)arr[i] * arr[i]) - ((long long)(i + 1) * (i + 1));
    }

    int A = (AminusB * AminusB + A2minusB2) / (2 * AminusB);
    int B = (AminusB * AminusB + A2minusB2) / (2 * AminusB) - AminusB;
    vector<int> ans = {A, B};
    return ans;
}