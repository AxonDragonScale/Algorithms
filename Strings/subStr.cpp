
// https://www.interviewbit.com/problems/implement-strstr/

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

// Returns index of b in a, -1 if b is not in a
int subStr(const string a, const string b) {
    int n = a.size();
    int m = b.size();

    for (int i = 0; i < n - m + 1; i++) {
        if (a[i] == b[0]) {
            int flag = 0;
            for (int j = 0; j < m; j++) {
                if (a[i + j] != b[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) return i;
        }
    }

    return -1;
}

int main() {
    string s, a;
    cin >> s >> a;

    cout << subStr(s, a) << endl;

    return 0;
}
