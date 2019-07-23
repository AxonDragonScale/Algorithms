// https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/

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

string rearrangeChars(string &s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    priority_queue<pair<int, char>> maxHeap;  // push all chars and their freqs in maxHeap
    for (auto p : freq) maxHeap.push({p.second, p.first});

    pair<int, char> prev = {-1, '#'};  // initially prev is dummy
    string ans;
    while (!maxHeap.empty()) {
        pair<int, char> k = maxHeap.top();
        maxHeap.pop();

        ans += k.second;
        k.first--;

        if (prev.first > 0) maxHeap.push(prev);  // we insert prev back in maxHeap as there is a diff char at the end
        prev = k;
    }

    if (ans.size() != s.size())
        return "Not Valid";
    else
        return ans;
}

int main() {
    string s;
    cin >> s;

    cout << rearrangeChars(s) << endl;

    return 0;
}
