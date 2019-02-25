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

    vi arr(n);
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    int l = 0, r = n-1;
    while(l<r) {
        int mid = (l+r)/2;

        if(arr[mid] > arr[r]) l = mid + 1;
        else r = mid;
    }

    if(l == r) {
        cout<<"Min element is "<<arr[l]<<" at index "<<l<<endl;
    }	

	return 0;
}