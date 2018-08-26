// https://www.geeksforgeeks.org/edit-distance-dp-5/
// https://practice.geeksforgeeks.org/problems/edit-distance/0

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

using namespace std;

int t, n1, n2;
string s1,s2;
int dp[100][100];

void editDistance() {
    
    for(int i = 0; i<=n1; i++) {
        for(int j = 0; j<=n2; j++) {
            
            if(i == 0) {    
                // if 1st string is empty, add all elements in 2nd string
                dp[i][j] = j;
            } else if(j == 0) {
                // if 2nd string is empty, remove all from 1st string
                dp[i][j] = i;
            } else if(s1[i-1] == s2[j-1]) {
                // if same, no cost
                dp[i][j] = dp[i-1][j-1];
            } else {
                // otherwise 1 + min cost(add, remove, replace)
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }
    
    cout<<dp[n1][n2]<<endl;
}

int main() {
	
	cin>>t;

	while(t--) {
	    cin>>n1>>n2;
	    cin>>s1>>s2;
	    
	    editDistance();
	}
	
	return 0;
}