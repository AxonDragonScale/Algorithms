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

class MinStack {
    stack<int> s;
    int min;

   public:
    MinStack() { min = INT_MAX; }

    void push(int x) {
        if (s.empty()) {
            min = x;
        }

        if (x >= min) {
            s.push(x);
        } else {
            s.push(x - min);
            min = x;
        }
    }

    void pop() {
        if (!s.empty()) {
            if (s.top() < 0) {
                min = min - s.top();
            }
            s.pop();
        }

        if (s.empty()) {
            min = INT_MAX;
        }
    }

    int top() {
        if (s.empty()) {
            return -1;
        } else {
            if (s.top() < 0) {
                return min;
            } else {
                return s.top();
            }
        }
    }

    int getMin() {
        if (s.empty()) {
            return -1;
        }
        return min;
    }
};

int main() {
    MinStack ms;

    // do stuff

    return 0;
}
