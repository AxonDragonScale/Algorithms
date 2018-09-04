
// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0
// https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/

#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

#define LN cout<<__LINE__<<endl
#define iPair pair<int, int>
#define ff first
#define ss second

using namespace std;

int main() {
	
	int n, temp;
	cin>>n;
	
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	
	int median = INT_MAX;
	for(int i = 1; i<=n; i++) {
	    cin>>temp;
	    
	    if(maxHeap.size() == minHeap.size()) {
	        if(temp < median) {
	            maxHeap.push(temp);
	        } else {
	            minHeap.push(temp);
	            maxHeap.push(minHeap.top());
	            minHeap.pop();
	        }
	        median = maxHeap.top();
	    } else if(maxHeap.size() == minHeap.size() + 1) {
	        if(temp < median) {
	            minHeap.push(maxHeap.top());
	            maxHeap.pop();
	            maxHeap.push(temp);
	        } else {
	            minHeap.push(temp);
	        }
	        median = (maxHeap.top() + minHeap.top())/2;
	    }
	    
	    cout<<median<<endl;
	}
	
	return 0;
}