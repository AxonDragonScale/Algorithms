// https://www.interviewbit.com/problems/longest-valid-parentheses/

int Solution::longestValidParentheses(string s) {
    int n = s.size();
    int ans = 0;

    deque<pair<char, int>> stack;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack.push_back({'(', i});
        } else if (s[i] == ')') {
            if (!stack.empty() && stack.back().first == '(') {
                stack.pop_back();
            } else {
                stack.push_back({')', i});
            }
        }
    }

    if (stack.empty())
        ans = n;
    else
        ans = stack.front().second;
    for (int i = 1; i < stack.size(); i++) {
        ans = max(ans, stack[i].second - stack[i - 1].second - 1);
    }
    if (!stack.empty()) ans = max(ans, n - stack.back().second - 1);

    return ans;
}