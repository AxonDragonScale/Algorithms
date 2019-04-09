
// https://www.geeksforgeeks.org/word-break-problem-using-backtracking/

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

void wordBreak(unordered_set<string> dictionary, string s, string res) {
    int n = s.size();

    for (int i = 1; i <= n; i++) {  // i is the length of the prefix, not the index
        string prefix = s.substr(0, i);

        if (isWordInDictionary(dictionary, prefix)) {
            if (i == n) {
                res += prefix;
                cout << res << endl;
                return;
            }

            wordBreak(dictionary, s.substr(i, n - i), res + prefix + " ");
        }
    }
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
        wordBreak(dictionary, s, "");
        cout << endl;
    }

    return 0;
}