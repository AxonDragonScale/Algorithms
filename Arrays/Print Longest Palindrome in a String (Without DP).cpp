
// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0
// https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
// https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/

// This is O(n^2) Soln. without DP (better)

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

int main() {
	
	int t;
	cin>>t;
	while(t--) {
	    string s;
	    deque<char> largest, cur;
	    
	    cin>>s;
	    
	    largest.push_back(s[0]);
	    for(int i = 1; i<s.size(); i++) {
	        cur.clear();
	        if(s[i-1] == s[i]) {    // even length palindromres
	            int l = i-1, r = i;
	            while(l >= 0 && r<s.size() && s[l] == s[r]) {
	                cur.push_front(s[l]);
	                cur.push_back(s[r]);
	                l--; r++;
	            }
	        }
	        
	        if(cur.size() > largest.size()) {
	            largest = cur;
	        }
	        
	        // odd length palindromes
	        cur.clear();
	        int l = i-1, r= i+1;
	        cur.push_back(s[i]);
	        while(l >= 0 && r<=s.size() && s[l] == s[r]) {
	            cur.push_front(s[l]);
	            cur.push_back(s[r]);
	            l--; r++;
	        }
	        
	        if(cur.size() > largest.size()) {
	            largest = cur;
	        }
	        
	    }
	    
	    for(char c : largest) {
	        cout<<c;
	    }
	    cout<<endl;
	}
	
	return 0;
}
