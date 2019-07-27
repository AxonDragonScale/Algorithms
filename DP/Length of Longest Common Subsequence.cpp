// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
// https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0

// Problem based on this -
// https://www.geeksforgeeks.org/shortest-common-supersequence/
// Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.
// Soln - The shortest common supersequence will have the LCS + remaining characters that aren't common.
// so the answer will be len(str1) + len(str2) - LCS. (Common character in subsequence should only be included once)
// OR see sol last soln in above link

#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

void LCS(string &s1, string &s2, int l1, int l2) {
    vector<vector<int>> lcs(l1 + 1, vector<int>(l2 + 1, 0));
    // lcs[i][j] stores the length of LCS of s1[0..i-1]and s2[0..j-1]
    // i.e considering only first i and j elements of s1 and s2
    // Initialize with 0 as base case, if length of any is 0, then lcs is 0;

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                lcs[i][j] = 1 + lcs[i - 1][j - 1];  // include the common element in LCS
            } else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    cout << lcs[l1][l2] << endl;
}

int main() {
    int t, l1, l2;
    cin >> t;

    string s1, s2;

    while (t--) {
        cin >> l1 >> l2;
        cin >> s1 >> s2;

        LCS(s1, s2, l1, l2);
    }

    return 0;
}