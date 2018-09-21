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

// not lexicographic, allows duplicates
void permute(string &s, int l, int r) {
    if(l == r) {
        cout<<s<<" ";
    } else {
        for(int i = l; i<=r; i++) {
            swap(s[l], s[i]);
            permute(s, l+1, r);
            swap(s[l], s[i]);   // backtrack
        }
    }
}

// http://www.cplusplus.com/reference/algorithm/next_permutation/?kw=next_permutation
// lexicograhic order and takes care of duplicates as well
void permute(string &s) {
    sort(s.begin(), s.end());   // sort lexicographically
    
    do {
        cout<<s<<" ";
    } while(next_permutation(s.begin(), s.end()));
}

// this is good, fully implemented
// https://www.geeksforgeeks.org/print-all-permutations-of-a-string-with-duplicates-allowed-in-input-string/

int main() {

	int t;
	string s;
	
	cin>>t;
	while(t--) {
	    cin>>s;
	    permute(s, 0, s.size()-1);
	    cout<<endl;
	}

	return 0;
}