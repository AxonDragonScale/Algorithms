
// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
// https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/

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

int t, noOfEggs, noOfFloors;

int eggDrop() {
    // dp[i][j] represents the minimum number of trials needed for i eggs and j floors
    int dp[noOfEggs+1][noOfFloors+1];
    int res;
    
    // if noOfFloors is 0, we need 0 trials and if its 1 we need only 1 trial
    // dp[0][0] = 0;
    for(int eggs = 1; eggs<=noOfEggs; eggs++) {
        dp[eggs][0] = 0;
        dp[eggs][1] = 1;
    }
    
    // if noOfEggs is 1 then we have to try each floor
    for(int floors = 1; floors<=noOfFloors; floors++) {
        dp[1][floors] = floors;
    }
    
    for(int eggs = 2; eggs<=noOfEggs; eggs++) {
        for(int floors = 2; floors<=noOfFloors; floors++) {
            
            dp[eggs][floors] = INT_MAX;
            for(int f = 1; f<=floors; f++) {    // f represents floor considered
            // max of cases where egg breaks at current floor and where it doesn't 
                res = 1 + max(dp[eggs-1][f-1], dp[eggs][floors-f]);
                if(res < dp[eggs][floors]) {
                    dp[eggs][floors] = res;
                }
            }
        }
    }
    
    return dp[noOfEggs][noOfFloors];
}

int main() {
	
	cin>>t;
	while(t--) {
	    cin>>noOfEggs>>noOfFloors;
	    cout<<eggDrop()<<endl;
	}
	
	return 0;
}