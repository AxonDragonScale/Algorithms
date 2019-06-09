// https://www.interviewbit.com/problems/excel-column-number/

int Solution::titleToNumber(string s) {
    int n = s.size();

    int ans = 0;
    for (int i = n - 1, j = 0; i >= 0; i--, j++) {
        int temp = s[i] - 64;
        ans += temp * pow(26, j);
    }

    return ans;
}
