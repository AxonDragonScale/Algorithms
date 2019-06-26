// https://www.interviewbit.com/problems/atoi/

int Solution::atoi(const string str) {
    string s = str;
    int i = 0;
    while (s[i] == ' ') i++;

    bool isNeg = false;
    if (s[i] == '-') {
        isNeg = true;
        i++;
    } else if (s[i] == '+') {
        i++;
    } else if (!isdigit(s[i])) {
        return 0;
    }

    int j = i;
    while (isdigit(s[j])) j++;
    s = s.substr(i, j - i);

    long long ans = 0;
    for (char c : s) {
        ans = ans * 10 + (c - '0');
        if (ans > INT_MAX) {
            if (isNeg) return INT_MIN;
            return INT_MAX;
        }
    }

    if (isNeg) ans *= -1;
    return ans;
}
