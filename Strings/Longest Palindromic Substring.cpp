// https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
// https://www.interviewbit.com/problems/longest-palindromic-substring/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define LN cout << __LINE__ << endl
#define ff first
#define ss second

using namespace std;

using iPair = pair<int, int>;
using vi = vector<int>;
using di = deque<int>;
using lli = long long int;

// An O(n) algo is also possible, called Manacher's Algorithm -> TODO

// No extra space, O(n^2) time
void printLPS(string &s) {
    int n = s.size();

    int maxIndex = 0, maxLen = 0;
    int curIndex, curLen, l, r;
    for (int i = 0; i < n; i++) {
        // find largest palindrome with center at i
        curIndex = i;
        curLen = 1;
        l = i - 1;
        r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            curIndex = l;
            curLen += 2;
            l--;
            r++;
        }

        if (curLen > maxLen) {
            maxIndex = curIndex;
            maxLen = curLen;
        }

        // find largest palindrome with center between i and i+1
        if (i + 1 < n && s[i] == s[i + 1]) {
            curIndex = i;
            curLen = 2;
            l = i - 1;
            r = i + 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                curIndex = l;
                curLen += 2;
                l--;
                r++;
            }

            if (curLen > maxLen) {
                maxIndex = curIndex;
                maxLen = curLen;
            }
        }
    }

    cout << string(s, maxIndex, maxLen);
}

// Takes O(n^2) space
// void printLPS(string &s) {
//     int n = s.size();
//     int index = 0, maxLength = 1;

//     deque<deque<bool>> dp(n, deque<bool>(n, false));
//     // dp[i][j] stores whether s[i..j] is a palindrome

//     for (int i = 0; i < n; i++) {
//         dp[i][i] = true;  // a single character is always a palindrome
//     }

//     for (int i = 0; i < n - 1; i++) {
//         if (s[i] == s[i + 1]) {
//             dp[i][i + 1] = true;  // if two characters are same they form a palindrome
//             index = i;
//             maxLength = 2;
//         }
//     }

//     for (int l = 3; l <= n; l++) {             // l is the length of the substring
//         for (int i = 0; i < n - l + 1; i++) {  // i is the starting index of the string
//             int j = i + l - 1;

//             if (s[i] == s[j] && dp[i + 1][j - 1] == true) {
//                 dp[i][j] = true;

//                 if (l > maxLength) {
//                     maxLength = l;
//                     index = i;
//                 }
//             }
//         }
//     }

//     cout << string(s, index, maxLength);
// }

int main() {
    string s;
    cin >> s;

    printLPS(s);

    return 0;
}
