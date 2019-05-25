
// https://www.interviewbit.com/problems/pretty-json/

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

vector<string> prettyJSON(string &s) {
    vector<string> ans;

    int indent = 0;
    string cur;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '[') {
            if (cur.empty()) {
                cur.append(indent, '\t');
                cur.push_back(s[i]);
                ans.push_back(cur);
                cur.clear();
            } else {
                ans.push_back(cur);
                cur.clear();
                cur.append(indent, '\t');
                cur.push_back(s[i]);
                ans.push_back(cur);
                cur.clear();
            }
            indent++;
        } else if (s[i] == '}' || s[i] == ']') {
            if (!cur.empty()) {
                ans.push_back(cur);
                cur.clear();
            }

            indent--;
            cur.append(indent, '\t');
            cur.push_back(s[i]);
            if (s[i + 1] == ',') continue;
            ans.push_back(cur);
            cur.clear();
        } else if (s[i] == ',') {
            cur.push_back(s[i]);
            ans.push_back(cur);
            cur.clear();
        } else {
            if (cur.empty()) {
                cur.append(indent, '\t');
            }
            cur.push_back(s[i]);
        }
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    vector<string> ans = prettyJSON(s);
    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}