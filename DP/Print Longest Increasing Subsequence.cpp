// Same principle as length of LIS
// https://www.geeksforgeeks.org/construction-of-longest-increasing-subsequence-using-dynamic-programming/

#include <iostream>
#include <vector>

using namespace std;

void printLIS(vector<int> &arr, int n) {
    vector< vector<int> > lis(n); 
    // Instead of storing length of LIS ending at i
    // we store the whole sequence as a list.
    
    lis[0].push_back(arr[0]); // LIS for 1st element is itself.
    
    for(int i = 1; i<n; i++) {
        for(int j = 0; j<i; j++) {
            if(arr[i] > arr[j] && lis[i].size() < lis[j].size() + 1) {
                // just like normal LIS, if arr[i] is greater and if LIS ending in j longer.
                lis[i] = lis[j];    // then new LIS is lis[j] + arr[i] (which is done after loop)
            }
        }
        lis[i].push_back(arr[i]);   // last element is arr[i] in LIS ending in i.
    }
    
    vector<int> max = lis[0]; //temp.
    for(vector<int> v : lis) {
        if(v.size() > max.size()) {
            max = v;
        }
    }
    
    for(int i : max) {
        cout<<i<<" ";
    }
    
    cout<<endl;
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
        
        printLIS(arr, n);
    }
    
    return 0;
}