#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>

#define LN cout<<__LINE__<<endl

using namespace std;

int t, maxLen, len;
string s;
int freq[26];

int main() {
	
	cin>>t;
	while(t--) {
	    cin>>s;
	    
	    maxLen = 0;
	    len = 0;
	    for(int i = 0; i<26; i++) {
	        freq[i] = 0;
	    }
	    
	    int j = 0;  //start of substring
	    for(int i = 0; i<s.size(); i++) {
	        if(freq[s[i] - 'a'] == 0) {
	            freq[s[i] - 'a'] = 1;
	            len++;
	            if(len > maxLen) maxLen = len;
	        } else {
	            while(freq[s[i] - 'a'] != 0) {
	                freq[s[j++] - 'a'] -= 1;
	                len--;
	            }
	            freq[s[i] - 'a'] = 1; len++;
	            if(len > maxLen) maxLen = len;
	        }
	    }
	    
	    cout<<maxLen<<endl;
	}
	
	return 0;
}