// https://www.geeksforgeeks.org/lexicographic-rank-of-a-string/
// https://www.interviewbit.com/problems/sorted-permutation-rank/

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

// This method is O(n^2)
lli lexicographicRank(string &s) {
    int mod = 1000003;
    int n = s.size();
    lli mul = 1;

    lli rank = 1;
    for (int i = n - 1; i >= 0; i--) {
        // count number of chars smaller than s[i] in s[i+1 .. n-1]
        int countRight = 0;
        for (int j = i + 1; j < n; j++) {
            if (s[j] < s[i]) countRight++;
        }

        rank = (rank + countRight * mul) % mod;
        // for countRight smaller chars, then there are count * (num chars after this)!
        mul = (mul * (n - i)) % mod;  // mul is (n-1-i)! for any i
    }

    return rank;
}

// Note - Above we used mul to get factorial from 1 to n-1, but we cant do this for n-1 to 1
// because then we woudl have to divide which will give wrong result due to the mod

// This is O(n)
lli lexicographicRank(string &s) {
    int mod = 1000003;
    int n = s.size();

    vector<int> fac(n);
    fac[0] = 1;
    for (int i = 1; i < n; i++) {
        fac[i] = (i * fac[i - 1]) % mod;
    }

    vector<int> charCount(256, 0);
    for (int i = 0; i < n; i++) {
        charCount[s[i]]++;
    }

    lli rank = 1;
    for (int i = 0; i < n; i++) {
        // Find number of characters smaller than s[i] left
        int countLess = 0;
        for (int ch = 0; ch < s[i]; ch++) {
            countLess += charCount[ch];
        }

        rank = (rank + (lli)countLess * fac[n - 1 - i]) % mod;
        charCount[s[i]]--;
    }

    return rank;
}

int main() {
    string s;
    cin >> s;

    cout << lexicographicRank(s) << endl;

    return 0;
}
