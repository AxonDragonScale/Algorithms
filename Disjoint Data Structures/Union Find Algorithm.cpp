
// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/tutorial/

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
using di = deque<int>;
using lli = long long int;

// int root(vector< iPair > &arr, int i) {
// 	while(arr[i].ff != i) {	// the root is the parent of itself, keep going up till the parent of i is not i
// 		i = arr[i].ff;
// 	}

// 	return i;
// }

// Efficient version of root, calculates the grandfather each time and saves it
// reduces length of path by half each time
int root(vector<iPair> &arr, int i) {
    while (arr[i].ff != i) {
        arr[i] = arr[arr[i].ff];
        i = arr[i].ff;
    }

    return i;
}

bool find(vector<iPair> &arr, int a, int b) { return root(arr, a) == root(arr, b); }

void weightedUnion(vector<iPair> &arr, int a, int b) {
    int aRoot = root(arr, a);
    int bRoot = root(arr, b);

    if (arr[aRoot].ss < arr[bRoot].ss) {
        // if size of a's subset is less than b's subset, make bRoot the parent of aRoot
        arr[aRoot].ff = bRoot;
        arr[bRoot].ss += arr[aRoot].ss;
    } else {
        arr[bRoot].ff = aRoot;
        arr[aRoot].ss += arr[bRoot].ss;
    }
}

int main() {
    int n = 10;
    vector<iPair> arr(n);
    // arr[i].ff stores the parent of i, the root of a component is its own parent
    // arr[i].ss stores the size of the subset i is in.

    // Initially each element is in a seperate component, it is its own parent and root
    // and the size of each subset is 1
    for (int i = 0; i < n; i++) {
        arr[i].ff = i;
        arr[i].ss = 1;
    }

    // use union and find here

    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <vector>
// #include <stack>
// #include <queue>
// #include <deque>
// #include <set>
// #include <unordered_set>
// #include <map>
// #include <unordered_map>

// #define LN cout<<__LINE__<<endl
// #define ff first
// #define ss second

// using namespace std;

// using iPair = pair<int, int>;
// using vi = vector<int>;
// using di = deque<int>;
// using lli = long long int;

// int root(vi &arr, int i) {
// 	while(arr[i] != i) {	// the root is the parent of itself, keep going up till the parent of i is not i
// 		i = arr[i];
// 	}

// 	return i;
// }

// // Makes the root of b, the parent of root of a
// void union(vi &arr, int a, int b) {
// 	int aRoot = root(a);
// 	int bRoot = root(b);

// 	arr[aRoot] = bRoot;	// set aRoot's parent to bRoot
// }

// bool find(vi &arr, int a, int b) {
// 	return root(arr, a) == root(arr, b);
// }

// int main() {

// 	int n = 10;
// 	vi arr(n);	// arr[i] stores the parent of i, the root of a component is its own parent

// 	// Initially each element is in a seperate component, it is its own parent and root
// 	for(int i = 0; i<n; i++) {
// 		arr[i] = i;
// 	}

// 	// use union and find here

// 	return 0;
// }
