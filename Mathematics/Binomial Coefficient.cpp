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

// first mulitply all then divide to avoid decimal errors
lli binomialCoeff(int n, int k) {
	lli res = 1;
	k = min(k, n-k);

	for(int i = 0; i<k; i++) {
		res *= (n-i);
	}

	for(int i = 1; i<=k; i++) {
		res /= i;
	}

	return res;
}

int main() {

	int n,k;
	cin>>n>>k;

	cout<<binomialCoeff(n,k)<<endl;

	return 0;
}
