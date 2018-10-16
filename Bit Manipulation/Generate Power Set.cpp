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

// this method is O(n * 2^n)
void printPowerSet(string &s) {
	int setSize = s.size();
	int powerSetSize = pow(2, setSize);

	for(int count = 0; count < powerSetSize; count++) {
		for(int i = 0; i < setSize; i++) {	// if the ith bit of count is set, display the ith element of the set
			if(count & (1 << i)) {
				cout<<s[i];
			}
		}
		cout<<endl;
	}

}

// Another Method (harder, using backtracking) - https://www.geeksforgeeks.org/backtracking-to-find-all-subsets/

int main() {

	string mySet = "abcd";
	printPowerSet(mySet);	

	return 0;
}
