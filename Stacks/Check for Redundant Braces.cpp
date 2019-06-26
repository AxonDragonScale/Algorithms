// https://www.interviewbit.com/problems/redundant-braces/

int Solution::braces(string s) {
    int n = s.size();

    stack<int> stack;
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack.push(i);
        } else if (s[i] == ')') {
            int temp = stack.top();
            stack.pop();
            if (temp == mn - 1 && i == mx + 1) return 1;
            if (i == temp + 2) return 1;  // like - (x)
            mn = min(temp, mn);
            mx = max(i, mx);
        }
    }

    return 0;
}
