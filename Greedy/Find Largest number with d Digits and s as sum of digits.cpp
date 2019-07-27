// https://www.geeksforgeeks.org/find-the-largest-number-with-given-number-of-digits-and-sum-of-digits/

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

int main() {
    int digits, sumDigits;
    cin >> digits >> sumDigits;

    if (sumDigits == 0) {
        if (digits == 0)
            cout << 0 << endl;
        else
            cout << "Not possible" << endl;
        return;
    }

    if (sumDigits > 9 * digits) cout << "Not possible" << endl;

    vi ans(digits);
    for (int i = 0; i < digits; i++) {
        if (sumDigits > 9) {
            ans[i] = 9;
            sumDigits -= 9;
        } else {
            ans[i] = sumDigits;
            sumDigits = 0;
        }
    }

    for (int i : ans) cout << i;
    cout << endl;

    return 0;
}
