
// https://practice.geeksforgeeks.org/problems/overlapping-intervals/0
// https://www.geeksforgeeks.org/merging-intervals/

// This is O(nlogn), inplace solution.
#include <iostream>
#include <vector>
#include <algorithm>
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
using lli = long long int;

int main() {
    
	int t, n;
	vector< iPair > intervals(100);
	
	cin>>t;
	while(t--) {
	    cin>>n;
	    for(int i = 0; i<n; i++) {
	        cin>>intervals[i].ff>>intervals[i].ss;
	    }

	    sort(intervals.begin(), intervals.begin() + n);		// dont sort till end(), ever.
	    
	    int last = 0;
	    for(int i = 1; i<n; i++) {
	        if(intervals[i].ff <= intervals[last].ss) {
	            intervals[last].ss = max(intervals[last].ss, intervals[i].ss);
	        } else {
	            intervals[++last] = intervals[i];
	        }
	    }
	    
	    for(int i= 0; i <= last; i++) {
	        cout<<intervals[i].ff<<" "<<intervals[i].ss<<" ";
	    }
	    cout<<endl;
	}

	return 0;
}