// https://www.interviewbit.com/problems/palindrome-partitioning/
// Given a string s, partition s such that every string of the partition is a palindrome.
// Return all possible palindrome partitioning of s.

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

bool isPalindrome(string &s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }

    return true;
}

void util(string &s, vector<vector<string>> &ans, vector<string> &cur, int start) {
    string temp;

    if (start == s.size()) {
        ans.push_back(cur);
        return;
    }

    for (int i = start; i < s.size(); i++) {
        if (isPalindrome(s, start, i)) {
            temp = string(s, start, i - start + 1);
            cur.push_back(temp);

            util(s, ans, cur, i + 1);

            cur.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> cur;

    util(s, ans, cur, 0);

    return ans;
}

int main() {
    string s;
    cin >> s;

    vector<vector<string>> ans = partition(s);
    for (vector<string> v : ans) {
        for (string s : v) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
