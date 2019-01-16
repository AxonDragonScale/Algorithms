// Find the first and last occurence of an element using binary search

// For first
// When element at mid is equal to the target element, instead of taking it as the result
// we just do r = mid, if this is not the first occurence, in the next iteration r will get a 
// value less than this. For the first element l and r will be equal

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

    vector<int> a(n);
    for(int i = 0; i<n; i++) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());

    int k;      // k is the element of which we want to find occurences         
    cin>>k;

    int l = 0, r = n-1;
    int first = -1, last = -1;

    // First occurence
    while(l<r) {
        int mid = (l+r)/2;
        if(a[mid] < k) l = mid + 1;
        else r = mid;
    }
    if(a[l] != k) {
        cout<<"Not found"<<endl;
        return 0;
    }
    first = l;

    // Last occurence
    r = n-1;
    while(l < r) {
        int mid = (l+r)/2 + 1;
        if(k < a[mid]) r = mid-1;
        else l = mid;
    }
    last = l;

    cout<<"First Occurence : "<<first<<endl<<"Last Occurence : "<<last<<endl;

	return 0;
}
