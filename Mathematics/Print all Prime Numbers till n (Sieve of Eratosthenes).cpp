
// Algorithm to find all prime numbers till n

#include <iostream>
#include <cmath>
#include <algorithm>
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
using lli = long long int;

int main() {

	int n, i, j;
	cin>>n;

	vector<int> primes(n+1, 1);
	primes[0] = 0;
	primes[1] = 0;


	for(i = 2; i<=sqrt(n); i++) {
		if(primes[i] == 0) continue;

		j = 2;
		while(i*j <= n) {
			primes[i*j] = 0;
			j++;
		}
	}

	for(int i = 2; i<=n; i++) {
		if(primes[i] == 1) cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}
