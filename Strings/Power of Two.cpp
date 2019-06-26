// https://www.interviewbit.com/problems/power-of-2/

// Find if Given number is power of 2 or not.
// More specifically, find if given number can be expressed as 2^k where k >= 1.

string divideByTwo(string s) {
    int n = s.size();
    string ans;

    int i = 0;
    int temp = s[i] - '0';
    if (i + 1 < n && temp < 2) temp = temp * 10 + (s[++i] - '0');

    while (i < n) {
        ans += (temp / 2) + '0';
        temp = temp % 2;

        i++;
        if (i < n) temp = temp * 10 + (s[i] - '0');
    }

    if (temp > 0) return "X";
    return ans;
}

int Solution::power(string s) {
    if (s == "1") return 0;

    while (s != "1") {
        s = divideByTwo(s);
        if (s[0] == 'X') return 0;
    }

    return 1;
}
