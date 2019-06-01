// https://practice.geeksforgeeks.org/problems/smallest-distant-window/0

#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>

#define LN cout<<__LINE__<<endl

using namespace std;

int t, distinctCount, minlen, countChanged;
string s;
deque<char> dq;
int freq[26];


int main() {
	
	cin>>t;
	while(t--) {
	    cin>>s;
	    
	    distinctCount = 0;
	    minlen = 0;
	    countChanged = 0;
	    dq.clear();
	    for(int i = 0; i<26; i++) {
	        freq[i] = 0;
	    }
	    
	    for(int i = 0; i<s.size(); i++) {
	        dq.push_back(s[i]);
	        countChanged = 0;
	        if(freq[s[i] - 'a'] == 0) {
	            distinctCount++;
	            countChanged = 1;
	        }
	        freq[s[i] - 'a'] += 1;
	        
	        while(!dq.empty() && freq[dq.front() - 'a'] > 1) {
	            freq[dq.front() - 'a'] -= 1;
	            dq.pop_front();
	            //cout<<dq.size()<<" size"<<endl;
	        }
	        
	        if(countChanged) minlen = dq.size();
	        
	        if(minlen > dq.size()) {
	            minlen = dq.size();
	        }
	        
	    }
	    
	    cout<<minlen<<endl;
	    
	}
	
	return 0;
}