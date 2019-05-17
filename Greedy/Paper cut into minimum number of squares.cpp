// https://www.geeksforgeeks.org/paper-cut-minimum-number-squares/

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

int minSquares(int a, int b) {
    if (a < b) return minSquares(b, a);
    if (a == b) return 1;

    // be is the smaller side, make as many squares of side b as possible (a/b)
    // recursively do this for b, a%b

    if (a % b == 0) {
        return a / b;
    } else {
        return a / b + minSquares(b, a % b);
    }
}

int main() {
    int length, width;
    cin >> length >> width;

    cout << minSquares(length, width) << endl;

    return 0;
}
