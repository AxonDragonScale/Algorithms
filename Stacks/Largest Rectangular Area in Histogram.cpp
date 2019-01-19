
// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#define LN cout<<__LINE__<<endl
#define ff first
#define ss second

using namespace std;

using iPair = pair<int, int>;
using vi = vector<int>;
using di = deque<int>;
using lli = long long int;

int main() {

	int t;
    cin>>t;
	while(t--) {
	    lli n; 
	    cin>>n;
	    
	    vector<lli> hist(n);
	    for(int i = 0; i<n; i++) {
	        cin>>hist[i];
	    }
	    
	    stack<lli> s;
        lli maxArea = 0;
        lli topIndex, areaWithTop;

        for(int i = 0; i<n; ) {
            if(s.empty() || hist[s.top()] <= hist[i]) {
                // If the top of stack is less than the current element push to stack
                s.push(i++);
            } else {
                // If top of stack is larger than current element, pop the top and 
                // calculate the area of rectangle with that as the smallest bar
                topIndex = s.top();
                s.pop();

                areaWithTop = hist[topIndex] * (s.empty() ? i : (i - s.top() - 1));
                maxArea = max(maxArea, areaWithTop);
            }
        }

        // pop the remaining bars from the stack
        while(!s.empty()) {
            topIndex = s.top();
            s.pop();

            areaWithTop = hist[topIndex] * (s.empty() ? (n) : (n - s.top() - 1));
            maxArea = max(maxArea, areaWithTop);
        }

        cout<<maxArea<<endl;
	}

	return 0;
}