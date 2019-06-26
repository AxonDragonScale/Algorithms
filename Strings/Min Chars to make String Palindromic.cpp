// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

int Solution::solve(string s) {
    int n = s.size();

    int ans = 0;
    int i = 0, j = n - 1;
    while (i < j) {
        if (s[i] == s[j]) {
            int m = i, n = j;
            while (m < n && s[m] == s[n]) {
                m++;
                n--;
            }
            if (m >= n) return ans;

            j--;
            ans++;
        } else {
            j--;
            ans++;
        }
    }

    return ans;
}
