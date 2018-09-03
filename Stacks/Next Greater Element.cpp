#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>

#define LN cout<<__LINE__<<endl
#define iPair pair<int, int>
#define ff first
#define ss second

using namespace std;

int t, n;
int arr[1000];

void printNGE() {
    int NGE[n];
    stack<int> s;
    s.push(0);  // stack will store indexes and not elements
    
    // arr[i] is the 'next' element
    for(int i = 1; i<n; i++) {
        // arr[i] will be NGE for all top elements in stack lesser than it
        while(!s.empty() && arr[s.top()] < arr[i]) {
            NGE[s.top()] = arr[i];
            s.pop();
        }
        
        s.push(i);
    }
    
    // Elements still left in stack have no greater element
    while(!s.empty()) {
        NGE[s.top()] = -1;
        s.pop();
    }
    
    for(int i = 0; i<n; i++) {
        cout<<NGE[i]<<" ";
    }
    cout<<endl;
}

int main() {
	
	cin>>t;
	while(t--) {
	    cin>>n;
	    for(int i = 0; i<n; i++) {
	        cin>>arr[i];
	    }
	    
	    printNGE();
	}
	
	return 0;
}