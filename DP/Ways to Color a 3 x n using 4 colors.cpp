// https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/
// https://www.geeksforgeeks.org/ways-color-3n-board-using-4-colors/

// Given a 3Xn board, find the number of ways to color it using at most 4 colors such that no two adjacent boxes have
// same color. Diagonal neighbors are not treated as adjacent boxes.

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

// Let A,B,C,D be the 4 colors
// color3 is number of ways to color a column using 3 colors (ABC), for 1 column its 24 (4*3*2)
// color2 is number of ways to color a column using 2 colors (ABA), for 1 xolumn its 12 (4*3*1)
// From a color3 column, there are 11 ways to get next color3 column and 5 ways to get next color2 column
// From a color2 column, there are 7 ways to get next color3 column and 10 ways to get next color2 column
// SEE GFG for better explaination

int waysToColor(int n) {
    if (n == 0) return 0;

    int mod = 1e9 + 7;
    lli color3 = 24, color2 = 12, temp;
    for (int i = 2; i <= n; i++) {
        temp = color3;

        color3 = (11 * color3 + 10 * color2) % mod;
        color2 = (5 * temp + 7 * color2) % mod;
    }

    return (color3 + color2) % mod;
}

int main() {
    int n;
    cin >> n;

    cout << waysToColor(n) << endl;

    return 0;
}
