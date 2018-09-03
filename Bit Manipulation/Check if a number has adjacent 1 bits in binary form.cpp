
// https://www.geeksforgeeks.org/check-number-two-adjacent-set-bits/
// https://www.youtube.com/watch?v=vCBaiGkDItM

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>

#define LN cout<<__LINE__<<endl
#define iPair pair<int, int>
#define ff first
#define ss second

using namespace std;

int t;
long long int n;

int main() {
	
	cin>>t;
	while(t--) {
	    cin>>n;
	    
	    // is there aren't any adjacent 1s, then AND after right shift will give zero
	    if(n & (n>>1)) {
	        cout<<"Yes"<<endl;
	    } else {
	        cout<<"No"<<endl;
	    }
	}
	
	return 0;
}