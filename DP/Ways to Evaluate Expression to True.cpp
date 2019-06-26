// https://www.interviewbit.com/problems/evaluate-expression-to-true/

// Given expression with operands (T, F) and operators (&, |, ^) , in how many ways can you evaluate the expression to
// true, by grouping in different ways?

int mod = 1003;

int utilT(string &s, vector<vector<int>> &dpT, vector<vector<int>> &dpF, int l, int r);

int utilF(string &s, vector<vector<int>> &dpT, vector<vector<int>> &dpF, int l, int r) {
    if (l == r) {
        if (s[l] == 'F')
            return 1;
        else
            return 0;
    }

    int &ans = dpF[l][r];
    if (ans != -1) return ans;

    ans = 0;
    for (int i = l + 1; i < r; i += 2) {
        if (s[i] == '&') {
            ans = (ans + utilF(s, dpT, dpF, l, i - 1) * utilF(s, dpT, dpF, i + 1, r) +
                   utilT(s, dpT, dpF, l, i - 1) * utilF(s, dpT, dpF, i + 1, r) +
                   utilF(s, dpT, dpF, l, i - 1) * utilT(s, dpT, dpF, i + 1, r)) %
                  mod;
        } else if (s[i] == '|') {
            ans = (ans + utilF(s, dpT, dpF, l, i - 1) * utilF(s, dpT, dpF, i + 1, r)) % mod;
        } else if (s[i] == '^') {
            ans = (ans + utilT(s, dpT, dpF, l, i - 1) * utilT(s, dpT, dpF, i + 1, r) +
                   utilF(s, dpT, dpF, l, i - 1) * utilF(s, dpT, dpF, i + 1, r)) %
                  mod;
        }
    }

    return ans;
}

int utilT(string &s, vector<vector<int>> &dpT, vector<vector<int>> &dpF, int l, int r) {
    if (l == r) {
        if (s[l] == 'T')
            return 1;
        else
            return 0;
    }

    int &ans = dpT[l][r];
    if (ans != -1) return ans;

    ans = 0;
    for (int i = l + 1; i < r; i += 2) {
        if (s[i] == '&') {
            ans = (ans + utilT(s, dpT, dpF, l, i - 1) * utilT(s, dpT, dpF, i + 1, r)) % mod;
        } else if (s[i] == '|') {
            ans = (ans + utilT(s, dpT, dpF, l, i - 1) * utilT(s, dpT, dpF, i + 1, r) +
                   utilT(s, dpT, dpF, l, i - 1) * utilF(s, dpT, dpF, i + 1, r) +
                   utilF(s, dpT, dpF, l, i - 1) * utilT(s, dpT, dpF, i + 1, r)) %
                  mod;
        } else if (s[i] == '^') {
            ans = (ans + utilT(s, dpT, dpF, l, i - 1) * utilF(s, dpT, dpF, i + 1, r) +
                   utilF(s, dpT, dpF, l, i - 1) * utilT(s, dpT, dpF, i + 1, r)) %
                  mod;
        }
    }

    return ans;
}

int Solution::cnttrue(string s) {
    int n = s.size();

    vector<vector<int>> dpT(n, vector<int>(n, -1));
    vector<vector<int>> dpF(n, vector<int>(n, -1));

    return utilT(s, dpT, dpF, 0, n - 1);
}
