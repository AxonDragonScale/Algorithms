
// https://www.geeksforgeeks.org/sort-a-stack-using-recursion/
// https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/

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


// Method 1 : Using recursion
// void sortedInsert(stack<int> &s, int n) {
//     if(s.empty() || n > s.top()) {
//         s.push(n);
//     } else {    // if n is smaller than the largest element
//         int temp = s.top();
//         s.pop();
//         sortedInsert(s, n);
//         s.push(temp);
//     }
// }

// void sort(stack<int> &s) {
//     if(!s.empty()) {
//         int temp = s.top();
//         s.pop();
//         sort(s);
//         sortedInsert(s, temp);
//     }
// }

// Method 2 : Using temporary stack
void sort(stack<int> &s) {
    stack<int> t;

    while(!s.empty()) {
        int temp = s.top();
        s.pop();

        while(!t.empty() && t.top() > temp) {
            s.push(t.top());
            t.pop();
        }

        t.push(temp);
    }

    s = t;
}

int main() {

	int n, temp;
    stack<int> s;

    cin>>n;
    for(int i = 0; i<n; i++) {
        cin>>temp;
        s.push(temp);
    }

    sort(s);

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

	return 0;
}
