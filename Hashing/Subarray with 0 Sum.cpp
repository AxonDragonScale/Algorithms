
// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0
// https://www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <algorithm>
#include <climits>

#define LN cout<<__LINE__<<endl
#define iPair pair<int, int>
#define ff first
#define ss second

using namespace std;

int zeroSumSubArrayExists(int n) {
    int sum = 0; 
    int temp;
    unordered_set<int> sumSet;
    
    for(int i = 0; i<n; i++) {
        cin>>temp;
        sum += temp;
        
        if(sum == 0 || sumSet.find(sum) != sumSet.end()) {
        	// if sum is 0  or if sum repeats ( if sum repeats all elements between the first and second occurence add up to 0 )
            return 1;
        }
        
        sumSet.insert(sum);
    }
    
    return 0;
}


int main() {
    
    int t, n, flag;
    
	
	cin>>t;
	while(t--) {
	    cin>>n;
	    
	    flag = zeroSumSubArrayExists(n);
	    
	    if(flag == 1) {
	        cout<<"Yes"<<endl;
	    } else {
	        cout<<"No"<<endl;
	    }
	}
	
	return 0;
}