// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
// Read the article or wont understand it.
// This is O(nlogn) while DP solution is O(n^2).

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// Binary Search 
int ceilIndex(vector<int> &arr, int l, int r, int key) {
    while(r-l > 1) {
        int m = l + (r-l)/2;
        
        if(key <= arr[m]) {
            r = m;
        } else {
            l = m;
        }
    }
    
    return r;
}

int LIS(vector<int> &arr, int n) {
    if(arr.size() == 0) return 0;
    
    vector<int> tail(n, 0);
    tail[0] = arr[0];
    int length = 1; // will always point to empty slot in tail
    
    for(int i = 0; i<n; i++) {
        if(arr[i] < tail[0]) {  // If its smaller than the smallest element
            tail[0] = arr[i];
        } else if(arr[i] > tail[length - 1]) {
            // If its greater than the largest element
            tail[length++] = arr[i];
        } else {
            tail[ceilIndex(tail, -1, length-1, arr[i])] = arr[i];
        }
    }
    
    return length;
}

int main() {
    
    int t, n;
    cin>>t;
    
    vector<int> arr;
    
    while(t--) {
        cin>>n;
        
        arr.resize(n);
        for(int i = 0; i<n; i++) {
            cin>>arr[i];
        }
        
        cout<<LIS(arr, n)<<endl;
    }
    
	return 0;
}