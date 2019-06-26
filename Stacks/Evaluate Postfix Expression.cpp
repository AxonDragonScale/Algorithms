// https://www.interviewbit.com/problems/evaluate-expression/

#include <cctype>

int Solution::evalRPN(vector<string> &s) {
    deque<int> stack;

    int a, b, c;
    for (int i = 0; i < s.size(); i++) {
        c = s[i][0];
        if (s[i].size() == 1 && !isdigit(c)) {
            b = stack.back();
            stack.pop_back();  // first b then a
            a = stack.back();
            stack.pop_back();

            switch (c) {
                case '+':
                    stack.push_back(a + b);
                    break;
                case '-':
                    stack.push_back(a - b);
                    break;
                case '*':
                    stack.push_back(a * b);
                    break;
                case '/':
                    stack.push_back(a / b);
                    break;
            }
        } else {
            stack.push_back(stoi(s[i]));
        }
    }

    return stack.back();
}