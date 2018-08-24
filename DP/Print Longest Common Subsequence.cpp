// https://www.geeksforgeeks.org/printing-longest-common-subsequence/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printLCS(string &s1, string &s2, int l1, int l2) {
    
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
    
    // For printing the LCS
    int length = lcs[l1][l2];
    string ans(length, 0);
    
    int i = l1, j = l2, idx = length-1; // start at the right bottom corner
    while(i>0 && j>0) {
        
        // if current element is common add it to ans
        if(s1[i-1] == s2[j-1]) {    
            ans[idx] = s1[i-1];
            i--; j--; idx--;
        } else if(lcs[i-1][j] > lcs[i][j-1]) {
            // if current element is not common move towards the larger LCS by removing an element
            // from the appropriate string
            i--;
        } else {
            j--;
        }
    }
    
    cout<<ans<<endl;
}

int main() {
    
    int t, l1, l2;
    cin>>t;
    
    string s1, s2;
    
    while(t--) {
        cin>>l1>>l2;
        cin>>s1>>s2;
        
        printLCS(s1, s2, l1, l2);
    }
    
    return 0;
}