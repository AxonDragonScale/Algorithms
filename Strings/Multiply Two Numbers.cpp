// https://www.interviewbit.com/problems/multiply-strings/

// Given two numbers represented as strings, return multiplication of the numbers as a string.
// Note: The numbers can be arbitrarily large and are non-negative.
// Note: Your answer should not have leading zeroes. For example, 00 is not a valid answer.

string mul(string a, char b) {
    string ans;

    int carry = 0;
    int i = a.size() - 1;
    while (i >= 0) {
        int temp = ((a[i] - '0') * (b - '0')) + carry;

        ans = to_string(temp % 10) + ans;
        carry = temp / 10;
        i--;
    }

    if (carry > 0) ans = to_string(carry) + ans;
    return ans;
}

string add(string a, string b) {
    string ans;

    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0) {
        int temp = carry;
        if (i >= 0) temp += (a[i] - '0');
        if (j >= 0) temp += (b[j] - '0');

        ans = to_string(temp % 10) + ans;
        carry = temp / 10;
        i--;
        j--;
    }

    if (carry > 0) ans = to_string(carry) + ans;
    return ans;
}

string removeLeadingZeros(string s) {
    int i = 0;
    while (i < s.size() && s[i] == '0') i++;

    if (i == s.size()) return "0";
    return s.substr(i);
}

string Solution::multiply(string a, string b) {
    string ans;
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);

    string zeros;
    for (int i = b.size() - 1; i >= 0; i--) {
        ans = add(ans, mul(a, b[i]) + zeros);
        ans = removeLeadingZeros(ans);
        zeros += '0';
    }

    return ans;
}
