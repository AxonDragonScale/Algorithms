
// https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/		   -> O(n) solution	
// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
// https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/    -> DP O(n^2) solution - bad

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

int t, n, maxReach, cnt, stepsRemaining;
int arr[100];

int main() {
	
	cin>>t;
	while(t--) {
	    cin>>n;
	    
	    for(int i = 0; i<n; i++) {
	        cin>>arr[i];
	    }
	    
	    if(arr[0] == 0) {
	        cout<<-1<<endl;
	        continue;
	    }
	    
	    maxReach = arr[0];
	    cnt = 1;
	    stepsRemaining = arr[0];
	    
	    for(int i = 1; i<n; i++) {
	        if(i == n-1) {  // when we reach the end
	            cout<<cnt<<endl;
	            break;
	        }
	        
	        maxReach = max(maxReach, i+arr[i]);
	        stepsRemaining -= 1;
	        
	        if(stepsRemaining == 0) {
	            cnt++; 
	            // if we exhausted all stepsRemaining, we must have taken
	            // taken a jump in one of them (the one that gets us maxReach)
	            
	            if(i >= maxReach) {
	                // if current index or any previous index is greater than 
	                // maxReach we cant go forward
	                cout<<-1<<endl;
	                break;
	            }
	            stepsRemaining = maxReach - i;
	        }
	    }
	    
	}
	
	return 0;
}