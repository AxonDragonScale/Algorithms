// https://www.interviewbit.com/problems/sorted-permutation-rank-with-repeats/  -> TODO better solution
// https://www.geeksforgeeks.org/lexicographic-rank-string-duplicate-characters/

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

// If the first character is X, all permutations which had the first character less than X would come before this
// permutation when sorted lexicographically. Number of permutation with a character C as the first character = number
// of permutation possible with remaining N-1 character = (N-1)! / (p1! * p2! * p3! ... ) where p1, p2, p3 are the
// number of occurrences of repeated characters.

// This method works for small cases that dont give overflow
// (need special tricks for modular div)
lli lexicographicRank(string &s) {
    int n = s.size();

    vector<int> fac(n);
    fac[0] = 1;
    for (int i = 1; i < n + 1; i++) {
        fac[i] = (i * fac[i - 1]);
    }

    lli rank = 1;
    for (int i = 0; i <= n; i++) {
        // count number of chars smaller than s[i] in s[i+1 .. n-1]
        int countRight = 0;
        for (int j = i + 1; j < n; j++) {
            if (s[j] < s[i]) countRight++;
        }

        // count the frequency of duplicate characters
        unordered_map<char, int> freq;
        for (int j = i; j < n; j++) {  // Include current char
            freq[s[j]]++;
        }

        // product of factorials for duplicates (we have to divide by dup! for each char)
        int dFac = 1;
        for (iPair i : freq) {
            dFac *= fac[i.second];
        }

        rank = (rank + (countRight * fac[n - 1 - i]) / dFac);
    }

    return rank;
}

// Method 2
// Works for overflow cases
lli inverseNumber(int num) {
    // Inverse modulo : https://en.wikipedia.org/wiki/Modular_multiplicative_inverse
    // Calculate num ^ MOD-2  % MOD
    long long int ans = 1, base = (long long)num;
    int MOD = 1000003;
    int power = MOD - 2;
    while (power > 0) {
        if (power == 1) {
            return (ans * base) % MOD;
        }
        if (power % 2 == 0) {
            base = (base * base) % MOD;
            power /= 2;
        } else {
            ans = (ans * base) % MOD;
            power--;
        }
    }
    return ans;
}

int Solution::findRank(string s) {
    int mod = 1000003;
    int n = s.size();

    vector<lli> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (i * fac[i - 1]) % mod;
    }

    lli rank = 1;
    for (int i = 0; i < n; i++) {
        // count number of chars smaller than s[i] in s[i+1 .. n-1]
        int countRight = 0;
        for (int j = i + 1; j < n; j++) {
            if (s[j] < s[i]) countRight++;
        }

        // count the frequency of duplicate characters
        unordered_map<char, int> freq;
        for (int j = i; j < n; j++) {  // Include current char
            freq[s[j]]++;
        }

        // product of factorials for duplicates (we have to divide by dup! for each char)
        lli dFac = 1;
        for (iPair i : freq) {
            dFac = (dFac * inverseNumber(fac[i.second])) % mod;
        }

        rank = (rank + (countRight * fac[n - 1 - i] * dFac)) % mod;
    }

    return rank;
}

int main() {
    string s;
    cin >> s;

    cout << lexicographicRank(s) << endl;

    return 0;
}
