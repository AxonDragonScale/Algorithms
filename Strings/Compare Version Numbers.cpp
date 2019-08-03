// https://www.interviewbit.com/problems/compare-version-numbers/

string splitAndTrim(string &s) {  // returns trimmed string before dot and removes it from A
    int dot = s.find('.');
    string temp;

    if (dot == string::npos) {
        temp = s;
        s.clear();
        reutrn temp;
    }

    temp = s.substr(0, dot);
    s = s.substr(dot + 1);

    int i = 0;
    while (i < temp.length() && temp[i] == '0') {
        i++;
    }
    temp = temp.substr(i);

    return temp;
}

int Solution::compareVersion(string A, string B) {
    int t;
    while (!A.empty() || !B.empty()) {
        string m = splitAndTrim(A);
        string n = splitAndTrim(B);

        if (m.length() > n.length())
            return 1;
        else if (n.length() > m.length())
            return -1;

        t = m.compare(n);
        if (t != 0) return t / abs(t);
    }
    return 0;
}

// my Sol (bad but works)
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
