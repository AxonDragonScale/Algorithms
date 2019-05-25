
// Interviewbit version - https://www.interviewbit.com/problems/longest-substring-without-repeat/
int Solution::lengthOfLongestSubstring(string s) {
    map<char, int> freq;

    int start = 0, end = 0, len = 0, maxLen = 0;
    while (end < s.size()) {
        if (freq[s[end]] != 0) {
            while (freq[s[end]] != 0) {
                freq[s[start]]--;
                start++;
                len--;
            }
        }
        freq[s[end]]++;
        end++;
        len++;
        maxLen = max(maxLen, len);
    }

    return maxLen;
}

// https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring/0

#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

#define LN cout << __LINE__ << endl

using namespace std;

int t, maxLen, len;
string s;
int freq[26];

int main() {
    cin >> t;
    while (t--) {
        cin >> s;

        maxLen = 0;
        len = 0;
        for (int i = 0; i < 26; i++) {
            freq[i] = 0;
        }

        int j = 0;  // start of substring
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] != 0) {
                while (freq[s[i] - 'a'] != 0) {
                    freq[s[j++] - 'a'] -= 1;
                    len--;
                }
            }
            freq[s[i] - 'a'] = 1;
            len++;
            if (len > maxLen) maxLen = len;
        }

        cout << maxLen << endl;
    }

    return 0;
}