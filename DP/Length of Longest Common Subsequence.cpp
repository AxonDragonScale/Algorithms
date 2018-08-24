// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
// https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void LCS(string &s1, string &s2, int l1, int l2) {
    
    int lcs[l1+1][l2+1];
    // lcs[i][j] stores the length of LCS of s1[0..i-1]and s2[0..j-1]
    // i.e considering only first i and j elements of s1 and s2
    
    for(int i = 0; i<=l1; i++) {
        for(int j = 0; j<=l2; j++) {
            if(i == 0 || j == 0) {
                lcs[i][j] = 0;
            } else if(s1[i-1] == s2[j-1]) {
                lcs[i][j] = 1 + lcs[i-1][j-1];
                // take the common element in LCS
            } else {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    
    cout<<lcs[l1][l2]<<endl;
}

int main() {
    
    int t, l1, l2;
    cin>>t;
    
    string s1, s2;
    
    while(t--) {
        cin>>l1>>l2;
        cin>>s1>>s2;
        
        LCS(s1, s2, l1, l2);
    }
    
	return 0;
}