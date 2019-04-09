
// https://www.geeksforgeeks.org/word-break-problem-dp-32/

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

bool isWordInDictionary(unordered_set<string> dictionary, string s) {
    if (dictionary.find(s) != dictionary.end()) {
        return true;
    }

    return false;
}

int wordBreak(unordered_set<string> &dictionary, string &s) {
    int size = s.size();
    if (size == 0) return 1;

    vector<bool> dp(size + 1, false);
    // dp[i] is true if s[0..i] can be broken into words in the dictionary

    for (int i = 1; i <= size; i++) {
        // check if word starting at 0 and of length i is in dictionary
        if (dp[i] == false && isWordInDictionary(dictionary, s.substr(0, i))) {
            dp[i] = true;
        }

        if (dp[i] == true && i == size) {
            return 1;
        } else if (dp[i] == true) {
            for (int j = i + 1; j <= size; j++) {
                if (dp[j] == false && isWordInDictionary(dictionary, s.substr(i, j - i))) {
                    dp[j] = true;
                }

                if (j == size && dp[j] == true) {
                    return 1;
                }
            }
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