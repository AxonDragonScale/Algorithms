// https://www.interviewbit.com/problems/majority-element/
// https://www.geeksforgeeks.org/majority-element/

// Given an array of size n, find the majority element. The majority element is the element that appears more than
// floor(n/2) times. You may assume that the array is non-empty and the majority element always exist in the array.

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

// Only works if majority element exists. Otherwise we need to check if count of arr[mIndex] is > n/2 after this
int majorityElement(const vector<int> &arr) {
    int n = arr.size();

    int mIndex = 0;
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[mIndex] == arr[i])
            count++;
        else
            count--;

        // if the new elements are not majority element then count will keep decreasing until new majoirty element is
        // selected
        if (count == 0) {
            mIndex = i;
            count = 1;
        }
    }

    return arr[mIndex];
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << majorityElement(arr) << endl;

    return 0;
}
