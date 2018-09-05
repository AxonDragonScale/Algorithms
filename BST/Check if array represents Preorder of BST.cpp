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

// there should be no smaller element after the next greater element
bool canRepresentBST(int pre[], int n) {
    stack<int> s;
    
    int curRoot = INT_MIN;
    for(int i = 0; i<n; i++) {
        // pre[i-1] was the next greater for curRoot
        // so pre[i] should not be smaller than curRoot
        if(pre[i] < curRoot) {  
            return false;
        }
        
        // if pre[i] is on right of s.top()
        // till pre[i] is the next greater for s.top()
        while(!s.empty() && s.top() < pre[i]) {
            curRoot = s.top();
            s.pop();
        }
        
        s.push(pre[i]);
    }
    return true;
}
