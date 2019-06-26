// https://www.interviewbit.com/problems/divide-integers/
// http://qa.geeksforgeeks.org/3794/qa.geeksforgeeks.org/3794/divide-integers-without-multiplication-division-operator.html
// https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/

// How does this work ???????

int Solution::divide(int dividend, int divisor) {
    long long int n = dividend, d = divisor;

    if ((n == INT_MIN && d == -1) || d == 0) return INT_MAX;  // overflow coz :  -INT_MIN > INT_MAX
    if (d == 1) return n;
    int sign = (n < 0) ^ (d < 0) ? -1 : 1;

    n = abs(n);
    d = abs(d);

    long long int ans = 0, temp = 0;
    for (int i = 31; i >= 0; i--) {
        if (temp + (d << i) <= n) {
            temp += (d << i);
            ans |= 1ll << i;
        }
    }

    return sign * ans;
}
