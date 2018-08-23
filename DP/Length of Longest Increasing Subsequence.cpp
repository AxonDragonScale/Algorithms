// https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0

#include <iostream>
#include <vector>

using namespace std;

int LIS(vector<int> &arr, int n) {
    vector<int> lis(n, 1);  // lis[i] holds length of LIS ending at i
    
    // lis[0] is 1.
    for(int i = 1; i<n; i++) {
        for(int j = 0; j<i; j++) {
            if(arr[j] < arr[i] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;    // basically doing max(lis[i], lis[j] + 1)
            }
        }
    }
    
    int max = 0;
    for(int i = 0; i<n; i++) {
        if(max < lis[i]) max = lis[i];
    }
    
    return max;
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