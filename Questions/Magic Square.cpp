
// For odd values of n
// https://www.geeksforgeeks.org/magic-square/

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

int main() {

	int n;
	cin>>n;

	vector< vi > mat(n, vi(n, -1));
	int i = n/2, j = n-1;

	for(int iter = 1; iter<=n*n; iter++) {
		if(i == -1 && j == n) {
			i = 0; j = n-2;
		} else {
			if(j==n) j = 0;
			if(i==-1) i = n-1;
		}

		if(mat[i][j] == -1) {
			mat[i][j] = iter;
		} else {
			i = (i+1);
			j = j-2;
			if(i==n) i = 0;
			if(j<0) j = n+j;
			mat[i][j] = iter;
		}

		i--; j++;
	} 

	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
