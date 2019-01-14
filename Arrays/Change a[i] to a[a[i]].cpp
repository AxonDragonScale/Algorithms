// https://www.geeksforgeeks.org/rearrange-given-array-place/
// https://www.interviewbit.com/problems/rearrange-array/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#define LN cout<<__LINE__<<endl
#define ff first
#define ss second

using namespace std;

using iPair = pair<int, int>;
using vi = vector<int>;
using di = deque<int>;
using lli = long long int;

int main() {

	int n;
    cin>>n;

    vi a(n);
    for(int i = 0; i<n; i++) {
        cin>>a[i];
    }

    for(int i = 0; i<n; i++) {
        a[i] += (a[a[i]]%n)*n;
    }

    for(int i = 0; i<n; i++) {
        a[i] /= n;
    }

    for(int i = 0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

	return 0;
}
