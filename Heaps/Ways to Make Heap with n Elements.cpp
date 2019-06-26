// https://www.geeksforgeeks.org/number-ways-form-heap-n-distinct-integers/
// https://www.interviewbit.com/problems/ways-to-form-max-heap/

// Approach

// Suppose there are n distinct elements to be used in Max heap. Now it is for sure that the maximum element among this
// n distinct element will surely be placed on the root of the heap. Now there will be remaining (n-1) elements to be
// arranged. Now point to be remembered here is that the structure of the heap will remain the same. That is only the
// values within the node will change however the overall structure remaining the same. As structure of the heap remains
// the same, the number of elements that are present in the left sub-tree of the root (L) will be fixed. And similarly
// the number of the elements on the right sub-tree (R) of the root. And also following equality holds . L + R = (n-1)
// Now as all the remaining (n-1) elements are less than the element present at the root(The Max Element), whichever L
// elements among 'n-1' elements we put in the left sub-tree, it doesn’t matter because it will satisfy the Max Heap
// property.
// So now there are (n-1)CL ways to pickup L elements from (n-1) elements. And then recurse the solution.
// So final equation will be as follows :
// (n-1)CL * getNumberOfMaxHeaps(L) * getNumberOfMaxHeaps(R)
// So now the question remains only of finding L for given n. It can be found as follows:
// Find the height of the heap h = log2(n)
// Find the max number of elements that can be present in the hth level of any heap . Lets call it m. m = 2^h
// Find the number of elements that are actually present in last level(hth level) in heap of size n. Lets call it p.
// p = n - (2^h - 1)
// Now if the last level of the heap is more than or equal to exactly half filled, then L would be 2^h - 1
// However if it is half filled then it will reduced by the number of elements in last level left to fill exactly half
// of the last level. So final equation for L will be as follows :
//     = 2^h - 1 if p >= m/2
// L=
//     = 2^h - 1 - (m/2 - p) if p<(m/2)

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

int getnCr(deque<di> &nCr, int n, int r) {
    if (r > n) return 0;
    if (n <= 1 || r == 0) return 1;

    if (nCr[n][r] != -1) return nCr[n][r];
    nCr[n][r] = (getnCr(nCr, n - 1, r - 1) + getnCr(nCr, n - 1, r)) % 1000000007;
    return nCr[n][r];
}

int getLeft(int n) {
    if (n == 1) return 0;

    int h = log2(n);                     // in cmath
    int maxLastLevel = 1 << h;           // 2^h - max no of elements that can be present in hth level
    int lastLevel = n - ((1 << h) - 1);  // 2^h - 1 is the total number of nodes above hth level

    if (lastLevel >= maxLastLevel / 2) {
        return (1 << h) - 1;  // left subtree is fully filled
    } else {
        return (1 << h) - 1 - (maxLastLevel / 2 - lastLevel);
    }
}

int noOfHeaps(int n, di &dp, deque<di> &nCr) {
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];

    int m = 1e9 + 7;

    int left = getLeft(n);
    dp[n] = ((((lli)getnCr(nCr, n - 1, left) * noOfHeaps(left, dp, nCr)) % m * noOfHeaps(n - 1 - left, dp, nCr)) % m);
    return dp[n];
}

int waysToMakeHeap(int n) {
    di dp(n + 1, -1);
    deque<di> nCr(n + 1, di(n + 1, -1));

    return noOfHeaps(n, dp, nCr);
}

int main() {
    int n;
    cin >> n;

    cout << waysToMakeHeap(n) << endl;

    return 0;
}
