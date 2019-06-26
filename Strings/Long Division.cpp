// https://www.geeksforgeeks.org/divide-large-number-represented-string/

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

string longDivision(string &s, int divisor) {
    int n = s.size();
    string ans;

    int i = 0;
    int temp = s[i++] - '0';
    while (i < n && temp < divisor) temp = temp * 10 + (s[i++] - '0');

    while (i < n) {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + (s[i++] - '0');
    }

    ans += (temp / divisor) + '0';
    temp = (temp % divisor);

    // if(temp % divisor != 0) return "Not Divisible";     if you only want exact division

    if (ans.empty()) return "0";
    return ans;
}

int main() {
    string s;
    cin >> s;

    int divisor;
    cin >> divisor;

    cout << longDivision(s, divisor) << endl;

    return 0;
}
