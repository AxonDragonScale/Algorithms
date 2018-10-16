
// https://www.geeksforgeeks.org/insertion-sort/

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

void insertionSort(vi &arr) {
	int n = arr.size();

	for(int i = 1; i<n; i++) {
		int j = i-1; 
		int cur = arr[i];

		while(j>=0 && arr[j]>cur) {
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = cur;
	}
}

int main() {

	int n;
	cin>>n;

	vi arr(n);
	for(int i = 0; i<n; i++) {
		cin>>arr[i];
	}

	insertionSort(arr);

	for(int i = 0; i<n; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}
