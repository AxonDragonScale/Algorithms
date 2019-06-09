// https://www.interviewbit.com/problems/word-break-ii/
// https://www.geeksforgeeks.org/word-break-problem-using-backtracking/

// TODO -> InterviewBit's DP solution

bool isWordInDict(unordered_set<string> &dict, string s) { return dict.find(s) != dict.end(); }

void util(string s, unordered_set<string> &dict, int n, string cur, vector<string> &ans) {
    for (int i = 1; i <= n; i++) {
        string prefix = s.substr(0, i);

        if (isWordInDict(dict, prefix)) {
            if (i == n) {
                cur += prefix;
                ans.push_back(cur);
                return;
            }

            util(s.substr(i, n - i), dict, n - i, cur + prefix + " ", ans);
        }
    }
}

vector<string> Solution::wordBreak(string s, vector<string> &dictionary) {
    unordered_set<string> dict(dictionary.begin(), dictionary.end());

    int n = s.size();
    vector<string> ans;
    string cur;
    util(s, dict, n, cur, ans);
    return ans;
}
