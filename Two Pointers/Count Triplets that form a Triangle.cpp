// Given a sorted array, count the number of triangles that can be made using any 3 elements in the array as sides.

// https://www.geeksforgeeks.org/find-number-of-triangles-possible/ -> similar
// https://www.interviewbit.com/problems/counting-triangles/

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

int main() {
    int n;
    cin >> n;

    deque<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // conditions - a+b > c, b+c > a, a+c > b
    // but if we keep a,b,c such that a<b<c , b+c>a and a+c>b are automatically true
    // so we iterate over c from n-1 to 2 and use 2 pointer method on a = 0 and b with b<c
    // keep incrementing a till a[a] + a[b] > a[c] becomes true, then increment count (all pairs a= a to b-1 with b
    // fixed) decrement b and continue
    int count = 0;
    for (int k = n - 1; k >= 2; k--) {
        int i = 0, j = k - 1;  // 2 pointer method
        while (i < j) {
            if (arr[i] + arr[j] <= arr[k]) {
                i++;
            } else {
                count += j - i;
                j--;
            }
        }
    }

    cout << count << endl;

    return 0;
}
