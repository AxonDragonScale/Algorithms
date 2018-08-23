#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

using namespace std;

int knapsack(int noOfItems, int maxCapacity, vector<int> &weight, vector<int> &value) {
    int dp[noOfItems+1][maxCapacity+1];
    
    for(int i = 0; i<=noOfItems; i++) {
        for(int w = 0; w<=maxCapacity; w++) {
            if(i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if(weight[i-1] <= w) {
                dp[i][w] = max(value[i-1] + dp[i-1][w - weight[i-1]], dp[i-1][w]);
                //max of include (i-1)th item and exclude it.
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[noOfItems][maxCapacity];
}

int main() {
    
    int t, noOfItems, maxCapacity;
    cin>>t;
    
    vector<int> weight, value;
    
    while(t--) {
        cin>>noOfItems>>maxCapacity;
        weight.resize(noOfItems);
        value.resize(noOfItems);
        
        for(int i = 0; i<noOfItems; i++) {
            cin>>value[i];
        }
        
        for(int i = 0; i<noOfItems; i++) {
            cin>>weight[i];
        }
        
        cout<<knapsack(noOfItems, maxCapacity, weight, value)<<endl;
    }
	
	return 0;
}