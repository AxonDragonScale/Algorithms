// https://www.interviewbit.com/problems/sliding-window-maximum/
// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/  ->  very good

// we need elements in dq s.t. it has larger element with smaller index first
// then smaller element with larger index (skip smaller element with smaller indexes)
// put elements in dq such that no element has a smaller element before it
// for(int i = 0; i<k; i++) {
//     while(!dq.empty() && arr[dq.back()] <= arr[i])
//         dq.pop_back();   // remove smaller element with smaller index
//     dq.push_back(i);
// }

// O(n)
vector<int> Solution::slidingMaximum(const vector<int> &arr, int k) {
    int n = arr.size();
    if(k>n) k = n;
    
    vector<int> ans;
    deque<int> dq;
    
    // same as commented code
    for(int i = k-1; i>=0; i--) {
        if(dq.empty() || arr[i] > arr[dq.front()]) {
            dq.push_front(i);
        }
    }
    ans.push_back(arr[dq.front()]);
    
    for(int i = k; i<n; i++) {
        while(!dq.empty() && i - dq.front() >= k)   
            dq.pop_front();     // remove elements no longer in window
            
        while(!dq.empty() && arr[dq.back()] <= arr[i]) 
            dq.pop_back();      // remove elements smaller than latest
            
        dq.push_back(i);
        ans.push_back(arr[dq.front()]);
    }
    
    return ans;
}
