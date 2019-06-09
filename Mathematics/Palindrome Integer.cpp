// https://www.interviewbit.com/problems/palindrome-integer/

int Solution::isPalindrome(int n) {
    if (n < 0) return 0;
    int rev = 0;

    int temp = n;
    while (temp) {
        rev = rev * 10 + temp % 10;
        temp = temp / 10;
    }

    return n == rev;
}
