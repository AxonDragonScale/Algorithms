// https://leetcode.com/problems/reverse-words-in-a-string?envType=study-plan-v2&envId=top-interview-150

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words.
// The returned string should only have a single space separating the words. Do not include any extra spaces.

string reverseWords(string s) {
    reverse(s.begin(), s.end());

    int n = s.size();
    int left = 0;
    int right = 0;
    int i = 0;

    while (i < n) {
        while (i < n && s[i] == ' ') i++;
        if (i >= n) break;

        while (i < n && s[i] != ' ') s[right++] = s[i++];

        reverse(s.begin() + left, s.begin() + right);
        s[right++] = ' ';
        left = right;
        i++;
    }

    s.resize(right - 1);
    return s;
}
