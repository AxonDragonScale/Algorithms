
// When you x % m , where x is negative , it just gives -(abs(x) % m)
// so to get real x % m, you need to do add a mulitple of m to x to make it positive
// and then modulo it.

// m + (x%m) = m - (abs(x) % m) will also give real answer since x%m gives
// additive inverse of real
// (m + (x%m))%m will work for both +ve and -ve x.

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

	int x, m;
	cout<<x%m<<'\t'<<(m+(x%m))%m<<endl;

	return 0;
}
