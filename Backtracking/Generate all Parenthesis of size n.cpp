// https://www.interviewbit.com/problems/generate-all-parentheses-ii/

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.
// For example, given n = 3, a solution set is: "((()))", "(()())", "(())()", "()(())", "()()()"

void util(vector<string> &ans, string &cur, int open, int close) {
    if (open == 0 && close == 0) {
        ans.push_back(cur);
        return;
    }

    if (open == close) {
        cur += '(';
        util(ans, cur, open - 1, close);
        cur.pop_back();
    } else {
        if (open > 0) {
            cur += '(';
            util(ans, cur, open - 1, close);
            cur.pop_back();
        }

        cur += ')';
        util(ans, cur, open, close - 1);
        cur.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int n) {
    vector<string> ans;
    string cur;

    util(ans, cur, n, n);
    return ans;
}
