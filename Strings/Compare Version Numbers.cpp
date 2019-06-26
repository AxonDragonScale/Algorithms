// https://www.interviewbit.com/problems/compare-version-numbers/

int Solution::compareVersion(string a, string b) {
    long double av = 0, bv = 0;

    int m = a.size(), n = b.size();
    int i = 0, j = 0;
    while (i < m || j < n) {
        if (i < m) {
            int end = a.find('.', i);
            if (end != string::npos) {
                av = stold(a.substr(i, end - i));  // stoi may give out of range with long numbers
                i = end + 1;
            } else {
                av = stold(a.substr(i));
                i = m;
            }
        }

        if (j < n) {
            int end = b.find('.', j);
            if (end != string::npos) {
                bv = stold(b.substr(j, end - j));
                j = end + 1;
            } else {
                bv = stold(b.substr(j));
                j = n;
            }
        }

        if (av > bv)
            return 1;
        else if (av < bv)
            return -1;
        else {
            av = 0;
            bv = 0;
        }
    }

    return 0;
}
