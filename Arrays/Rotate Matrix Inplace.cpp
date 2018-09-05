
// https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space/0
// https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/

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

int  t, n;
int mat[10][10];

void rotateClockwise(int mat[10][10], int n) {
    for(int i = 0; i<n/2; i++) {    // as only n/2 cycles
	    for(int j = i; j<n-1-i; j++) {     // 
	        int temp = mat[i][j];
	        mat[i][j] = mat[n-1-j][i];  
	        mat[n-1-j][i] = mat[n-1-i][n-1-j];
	        mat[n-1-i][n-1-j] = mat[j][n-1-i];
	        mat[j][n-1-i] = temp;
	    }
    }
}

void rotateAnticlockwise(int mat[10][10], int n) {
    for(int i = 0; i<n/2; i++) {
	    for(int j = i; j<n-1-i; j++) {
	        int temp = mat[i][j];
	        mat[i][j] = mat[j][n-1-i];  
	        mat[j][n-1-i] = mat[n-1-i][n-1-j];
	        mat[n-1-i][n-1-j] = mat[n-1-j][i];
	        mat[n-1-j][i] = temp;
	    }
    }
}

int main() {
	
	cin>>t;
	while(t--) {
	    cin>>n;
	    
	    for(int i = 0; i<n; i++) {
	        for(int j = 0; j<n; j++) {
	            cin>>mat[i][j];
	        }
	    }
	    
	    rotateClockwise(mat, n);
	    
	    for(int i = 0; i<n; i++) {
	        for(int j = 0; j<n; j++) {
	            cout<<mat[i][j]<<" ";
	        }
	    }
	    cout<<endl;
	}
	
	return 0;
}
