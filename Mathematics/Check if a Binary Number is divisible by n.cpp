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

	int n, rem = 0;
	string s;
	cin>>s>>n;

	for(char c : s) {
		rem = (rem*2 + (c-'0'))%n;
	}

	if(rem == 0) {
		cout<<1<<endl;
	} else {
		cout<<0<<endl;
	}

	return 0;
}
