
// Algorithm to find all prime numbers till n
// this is O(nlogn)

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
using lli = long long int;

int main() {
    int n, i, j;
    cin >> n;

    vector<bool> primes(n + 1, true);
    primes[0] = false;
    primes[1] = false;

    for (i = 2; i <= sqrt(n); i++) {
        if (primes[i] == false) continue;

        j = i;  // multiples of j = 2 to i-1 already marked for previous iterations of i
        while (i * j <= n) {
            primes[i * j] = false;
            j++;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (primes[i] == 1) cout << i << " ";
    }
    cout << endl;

    return 0;
}
