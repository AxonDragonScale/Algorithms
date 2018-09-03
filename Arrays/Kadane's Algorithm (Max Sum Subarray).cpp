
// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

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

int t, n;
int arr[1000];

int main() {
	
	cin>>t;
	while(t--) {
	    cin>>n;
	    for(int i = 0; i<n; i++) {
	        cin>>arr[i];
	    }
	    
	    int max = INT_MIN, curMax = 0;
        for(int i = 0; i<n; i++) {
            curMax += arr[i];
            
            if(curMax > max) {
                max = curMax;
            }
            if(curMax < 0) {	// if curMax is -ve, we just start a new subarray
                curMax = 0;
            }
        }                     
	    cout<<max<<endl;
	}
	
	return 0;
}