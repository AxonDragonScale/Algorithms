// https://www.geeksforgeeks.org/word-break-problem-dp-32/
// https://www.geeksforgeeks.org/word-break-problem-trie-solution/ -> TODO

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
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

bool isWordInDict(unordered_set<string> dictionary, string s) { return dictionary.find(s) != dictionary.end(); }

// Method 1 - Optimized (BEST)
int wordBreak(unordered_set<string> &dict, string &s) {
    int n = s.size();
    if (n == 0) return 1;

    vector<bool> dp(n + 1, false);
    // dp[i] will be true if s[0..i] can be segmented into dictionary words

    vector<int> trueIdx;  // stores indices for which dp[i] is true
    trueIdx.push_back(-1);

    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = trueIdx.size() - 1; j >= 0; j--) {
            if (isWordInDict(dict, s.substr(trueIdx[j] + 1, i - trueIdx[j]))) {
                flag = true;
                break;
            }
        }

        if (flag) {
            dp[i] = true;
            trueIdx.push_back(i);
        }
    }

    return dp[n - 1];
}

// Method 2 - Less optimized (Easier to understand)
int wordBreak(unordered_set<string> &dict, string &s) {
    int n = s.size();
    if (n == 0) return 1;

    vector<bool> dp(n + 1, false);
    // dp[i] is true if s[0..i-1] can be broken into words in the dictionary

    for (int i = 1; i <= n; i++) {
        // check if word starting at 0 and of length i is in dict
        if (dp[i] == false && isWordInDict(dict, s.substr(0, i))) {
            dp[i] = true;
        }

        if (dp[i] == true && i == n) {
            return 1;
        } else if (dp[i] == true) {
            for (int j = i + 1; j <= n; j++) {
                if (dp[j] == false && isWordInDict(dict, s.substr(i, j - i))) {
                    dp[j] = true;
                }
            }
            if (dp[n] == true) return 1;
        }
    }

    return 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        unordered_set<string> dictionary;
        for (int i = 0; i < n; i++) {
            cin >> s;
            dictionary.insert(s);
        }

        cin >> s;
        cout << wordBreak(dictionary, s) << endl;
    }

    return 0;
}