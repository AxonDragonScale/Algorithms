
// https://www.geeksforgeeks.org/find-the-element-that-appears-once/
// In a stream one number appears only once while all others appear k times.

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

	int k, n;
    cin>>k>>n;
    
    vi arr(n);
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    int result = 0;
    int x, sum;

    for(int i = 0; i<32; i++) {      // since int is 32 bit
        sum = 0;
        x = 1 << i;

        for(int j = 0; j<n; j++) {
            if(arr[j] & x) {        // sum of bits at ith position
                sum++;
            }
        }

        if(sum % k) {               // as all numbers are either k times or only once, sum % k will be 0 or 1
            result = result | x;
        }
    }

    cout<<result<<endl;

	return 0;
}
