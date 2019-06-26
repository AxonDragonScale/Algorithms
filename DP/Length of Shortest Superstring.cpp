// https://www.geeksforgeeks.org/shortest-superstring-problem/
// https://www.interviewbit.com/problems/shortest-common-superstring/

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

// get min length combined string by overlapping
int maxOverlapLen(string a, string b, string &combinedString) {
    int maxOverlap = 0;
    int aLen = a.size(), bLen = b.size();

    // a before b -> last i chars of a overlap with first chars i of b
    for (int i = 1; i <= min(aLen, bLen); i++) {
        if (a.compare(aLen - i, i, b, 0, i) == 0) {  // same as a.substr(aLen-i, i) == b.substr(0, i)
            if (i > maxOverlap) {
                maxOverlap = i;
                combinedString = a + b.substr(i);
            }
        }
    }

    // b before a -> last i chars of b overlap with first i chars of a
    for (int i = 1; i <= min(aLen, bLen); i++) {
        if (b.compare(bLen - i, i, a, 0, i) == 0) {
            if (i > maxOverlap) {
                maxOverlap = i;
                combinedString = b + a.substr(i);
            }
        }
    }

    if (maxOverlap == 0) combinedString = a + b;
    return maxOverlap;
}

int lenShortestSuperString(vector<string> &v) {
    int n = v.size();

    while (n != 1) {
        int maxOverlap = INT_MIN, aIdx, bIdx, t;
        string combinedString;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string temp;
                if ((t = maxOverlapLen(v[i], v[j], temp)) >= maxOverlap) {  // we can also do > here
                    // this is an approximate algo, both > and >= may give correct or incorrect answers
                    maxOverlap = t;
                    combinedString = temp;
                    aIdx = i;
                    bIdx = j;
                }
            }
        }

        v[aIdx] = combinedString;
        v[bIdx] = v[n - 1];  // last

        n--;
        v.resize(n);
    }

    return v[0].size();
}

int main() {
    int n;
    cin >> n;

    vector<string> v;
    for (int i = 0; i < n; i++) cin >> v[i];

    cout << lenShortestSuperstring(v) << endl;

    return 0;
}
