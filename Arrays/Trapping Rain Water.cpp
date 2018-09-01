
// https://practice.geeksforgeeks.org/problems/trapping-rain-water/0
// https://www.geeksforgeeks.org/trapping-rain-water/

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

int t, n, totalWater;
int height[100];
int maxLeft[100];   // store max height 0 to i
int maxRight[100];  // store max height i to n-1

int main() {
	
	cin>>t;
	while(t--) {
	    cin>>n;
	    for(int i = 0; i<n; i++) {
	        cin>>height[i];
	    }
	    
	    maxLeft[0] = height[0];
	    for(int i = 1; i<n; i++) {
	        maxLeft[i] = max(maxLeft[i-1], height[i]);
	    }
	    
	    maxRight[n-1] = height[n-1];
	    for(int i = n-2; i>=0; i--) {
	        maxRight[i] = max(maxRight[i+1], height[i]);
	    }
	    
	    totalWater = 0;
	    for(int i = 0; i<n; i++) {
	        totalWater += min(maxLeft[i], maxRight[i]) - height[i];
	    }
	    
	    cout<<totalWater<<endl;
	}
	
	return 0;
}