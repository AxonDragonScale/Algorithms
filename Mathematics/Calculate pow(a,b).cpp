#include <algorithm>
#include <climits>
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

// Modular exponentiation
// https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/
int power(int a, unsigned int b, int m) {
    int res = 1;  // Initialize result

    a = a % m;  // Update a if it is more than or equal to m

    while (b > 0) {
        // If b is odd, multiply a with result
        if (b & 1) res = (res * a) % m;

        // b must be even now
        b = b >> 1;  // b = b/2
        a = (a * a) % m;
    }
    return res;
}

// int power(int a, int b) {
//     if(b == 0) return 1;
//     if(b == 1) return a;

//     if(b%2 == 0) {
//         return power(a*a, b/2);
//     } else {
//         return a * power(a*a, (b-1)/2);
//     }
// }

int mod = 1e9 + 7;

int power(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;

    if (b % 2 == 0) {
        return power((lli)a * (lli)a, b / 2) % mod;
    } else {
        return (power((lli)a * (lli)a, (b - 1) / 2) * a) % mod;
    }
}

// https://www.interviewbit.com/problems/implement-power-function/
int pow(int a, int b) {
    if (a == 0) return 0;
    if (b == 0) return 1;

    lli ans = 1, base = a;
    while (b > 0) {
        if (b % 2 == 0) {
            base = (base * base) % mod;
            b = b / 2;
        } else {
            ans = (ans * base) % mod;
            b--;
        }
    }

    while (ans < 0) ans = mod + ans;
    return (int)ans;
}

// or
int pow(int a, int b) {
    if (a == 0) return 0;  // needed on interviewbit
    if (b == 0) return 1;

    lli y;
    if (b % 2 == 0) {
        y = pow(a, b / 2);
        y = (y * y) % mod;
    } else {
        y = a % mod;
        y = (y * pow(a, b - 1)) % mod;
    }

    return (int)((y + mod) % mod);
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << power(a, b);

    return 0;
}
