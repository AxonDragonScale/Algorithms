// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>

#define LN cout<<__LINE__<<endl

using namespace std;

int t, n, flag;
char str[500];
int freq[26];

int main() {
	
	cin>>t;
	while(t--) {
	    cin>>n;
	    
	    for(int i = 0; i<26; i++) {
	        freq[i] = 0;
	    }
	    
	    for(int i = 0; i<n; i++) {
	        cin>>str[i];
	        freq[str[i]-'a'] += 1;
	        
	        flag = 0;
	        for(int j = 0; j<=i; j++) {
	            if(freq[str[j]-'a'] == 1) {
	                cout<<str[j]<<" ";
	                flag = 1;
	                break;
	            }
	        }
	        if(flag == 0) cout<<-1<<" ";
	    }
	    cout<<endl;
	}
	
	return 0;
}