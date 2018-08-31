
// https://www.geeksforgeeks.org/given-a-number-find-next-smallest-palindrome-larger-than-this-number/
// https://practice.geeksforgeeks.org/problems/next-smallest-palindrome/0

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <climits>

#define LN cout<<__LINE__<<endl

using namespace std;

int t, n;
int num[1000];

bool isAllNine() {
    for(int i = 0; i<n; i++) {
        if(num[i] != 9) return false;
    }
    
    return true;
}

void util() {
    int i, j; // if n is even, i and j are middle elements
              // if n is odd, i is left and right to the middle
    
    i = n/2 - 1;
    j = n%2 == 0 ? n/2 : n/2 + 1;
    
    bool leftSmaller = false;
    // is the left element after the mirrored part is smaller
    // middle element needs to be incremented if left is smaller
    // or if its already a palindrome
    
    // keep moving i to the left and j to right till elements are same
    while(i>=0 && num[i] == num[j]) {
        i--; j++;
    }
    
    
    if(i == 0 || num[i] < num[j]) {
        leftSmaller = true;
    }
    
    // mirror the left side
    while(i >= 0) num[j++] = num[i--];
    
    if(leftSmaller) {
        int carry;
        i = n/2 - 1;
        
        if(n%2 == 0) {
            j = n/2;
            carry = 1;
        } else {
            j = n/2 + 1;
            num[n/2] += 1; //increment middle element
            carry = num[n/2]/10;
            num[n/2] = num[n/2]%10;
        }
        
        while( i>=0 ) {
            num[i] += carry;
            carry = num[i]/10;
            num[i] = num[i]%10;
            num[j] = num[i];
            j++; i--;
        }
    }
    
    for(int i = 0; i<n; i++) {
        cout<<num[i]<<" ";
    }
    cout<<endl;
    
}

void nextGreaterPalindrome() {
    if(isAllNine()) {
        cout<<"1 ";
        for(int i = 1; i<n; i++) {
            cout<<"0 ";
        }
        cout<<"1"<<endl;
    } else {
        util();
    }
}

int main() {
	
	cin>>t;
	while(t--) {
	    cin>>n;
	    
	    for(int i = 0; i<n; i++) {
	        cin>>num[i];
	    }
	    
	    nextGreaterPalindrome();
	}
	
	return 0;
}