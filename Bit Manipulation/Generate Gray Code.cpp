// https://www.geeksforgeeks.org/given-a-number-n-generate-bit-patterns-from-0-to-2n-1-so-that-successive-patterns-differ-by-one-bit/
// https://www.geeksforgeeks.org/generate-n-bit-gray-codes-set-2/   -> TODO

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define LN cout << __LINE__ << endl
#define ff first
#define ss second

using namespace std;

using iPair = pair<int, int>;
using vi = vector<int>;
using di = deque<int>;
using lli = long long int;

// method 1
// start with 0 and 1 as codes
// append a copy of the codes in reverse order
// prepend 0 to half the codes and 1 to the other half
void printGrayCodes(int n) {
    if (n <= 0) return;

    vector<string> ans;
    ans.push_back("0");
    ans.push_back("1");

    for (int i = 1 << 1; i < (1 << n); i = i << 1) {  // i = 2,4,8,16...2^n
        for (int j = i - 1; j >= 0; j--) {            // push all in reverse order
            ans.push_back(ans[j]);
        }

        for (int j = 0; j < i; j++) {       // new size of ans is 2i
            ans[j] = "0" + ans[j];          // prepend 0 to first half
            ans[j + i] = "1" + ans[j + i];  // prepend 1 to second half
        }
    }

    for (string s : ans) {
        cout << s << endl;
    }
}

// method 2

int main() {
    int n;
    cin >> n;

    printGrayCodes(n);

    return 0;
}
