
// https://www.interviewbit.com/problems/roman-to-integer/

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

int getVal(char c) {
    switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
}

int romanToInt(string s) {
    int n = s.size();
    int ans = 0;

    char prev = 'I';
    for (int i = n - 1; i >= 0; i--) {
        char c = s[i];
        if (getVal(c) < getVal(prev)) {
            ans -= getVal(c);
        } else {
            ans += getVal(c);
        }

        prev = c;
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << romanToInt(s);

    return 0;
}