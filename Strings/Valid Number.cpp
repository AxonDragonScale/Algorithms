// https://www.interviewbit.com/problems/valid-number/

int Solution::isNumber(const string str) {
    string s = str;
    int n = s.size();

    int i = 0;
    while (i < n && s[i] == ' ') i++;

    if (i < n && (s[i] == '-' || s[i] == '+')) i++;
    if (i < n && !isdigit(s[i]) && s[i] != '.') return 0;
    if (i == n) return 0;  // ends without any digits

    while (i < n && isdigit(s[i])) i++;

    if (s[i] == '.') {                                   // no digits before dot is okay
        if (i + 1 >= n || !isdigit(s[i + 1])) return 0;  // there should be a digit after dot

        i++;
        while (isdigit(s[i])) i++;
    }

    if (s[i] == 'e') {
        if (!isdigit(s[i - 1])) return 0;  // no digit before e is not okay
        i++;
        if (s[i] == '-' || s[i] == '+') i++;  // exponent can be pos or neg but not fraction (here) so skip that

        while (isdigit(s[i])) i++;
    }

    while (s[i] == ' ') i++;  // ignore trailing spaces

    if (i == n) return 1;
    return 0;
}
