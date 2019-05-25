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

// The lli is very important
string fractionToString(int numerator, int denominator) {
    lli n = numerator, d = denominator;
    if (n == 0) return "0";

    string ans;
    if (n < 0 ^ d < 0) ans += '-';  // if exactly one of them is negative
    n = abs(n);
    d = abs(d);  // remove signs

    ans += to_string(n / d);  // add integral part

    if (n % d == 0) {
        return ans;
    } else {
        ans += '.';
        unordered_map<int, int> remainderIndex;  // store index at which the remainder occured

        lli r = n % d;
        while (r != 0) {
            if (remainderIndex.find(r) != remainderIndex.end()) {
                ans.insert(remainderIndex[r], 1, '(');
                ans += ')';
                break;
            }

            remainderIndex[r] = ans.size();
            r *= 10;
            ans.push_back('0' + r / d);

            r %= d;
        }
    }

    return ans;
}

int main() {
    int n, d;
    cin >> n >> d;

    cout << fractionToString(n, d);

    return 0;
}
