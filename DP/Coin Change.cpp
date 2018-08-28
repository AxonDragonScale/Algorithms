
// https://www.geeksforgeeks.org/coin-change-dp-7/
// https://practice.geeksforgeeks.org/problems/coin-change/0

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>

#define LN cout<<__LINE__<<endl

using namespace std;

int t, sum, numOfCoins;
vector<int> coins;

void coinChange() {
    // sum+1 coz we consider the case when sum is 0 
    int dp[sum+1][numOfCoins];
    
    int jthCoinIncluded, jthCoinNotIncluded;
    
    for(int i = 0; i<numOfCoins; i++) {
        dp[0][i] = 1; // there is only one way to make 0 
                      // no matter how many coins we use
    }
    
    for(int i = 1; i<sum+1; i++) {
        for(int j = 0; j<numOfCoins; j++) {
            // i is the sum and j is the no of coins used
            jthCoinIncluded = i-coins[j] >= 0 ? dp[i-coins[j]][j] : 0;
            jthCoinNotIncluded = j>=1 ? dp[i][j-1] : 0;
            // if j is 0, 0 ways
            dp[i][j] = jthCoinIncluded + jthCoinNotIncluded;
        }
    }
    
    cout<<dp[sum][numOfCoins-1]<<endl;
}

int main() {
	
	cin>>t;
	while(t--) {
	    cin>>numOfCoins;
	    coins.resize(numOfCoins);
	    for(int i = 0; i<numOfCoins; i++) {
	        cin>>coins[i];
	    }
	    cin>>sum;
	    
	    coinChange();
	}
	
	return 0;
}