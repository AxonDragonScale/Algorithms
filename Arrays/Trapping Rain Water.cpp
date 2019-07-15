// https://practice.geeksforgeeks.org/problems/trapping-rain-water/0
// https://www.geeksforgeeks.org/trapping-rain-water/
// https://www.interviewbit.com/problems/rain-water-trapped/

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water
// it is able to trap after raining.

#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

#define LN cout << __LINE__ << endl
#define iPair pair<int, int>
#define ff first
#define ss second

using namespace std;

// method 1 (better)
// At each point we want to know if maxLeft is greater or maxRight as water = min(maxLeft, maxRight) - height[i].
// If arr[l] < arr[r] then maxRight is sure to be greater than arr[l], now if maxLeft is more than arr[l] then water is
// trapped.
int waterTrapped(const vector<int> &arr) {
    int n = arr.size();

    int water = 0;
    int maxLeft = 0, maxRight = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        if (arr[l] <= arr[r]) {
            if (arr[l] >= maxLeft)  // = is IMP
                maxLeft = arr[l];
            else
                water += maxLeft - arr[l];
            l++;
        } else {
            if (arr[r] >= maxRight)  // = is IMP
                maxRight = arr[r];
            else
                water += maxRight - arr[r];
            r--;
        }
    }

    return water;
}

// method 2 - uses extra space
int waterTrapped(const vector<int> &height) {
    int n = height.size();

    vector<int> maxLeft(n), maxRight(n);
    // maxLeft[i] stores max height in 0 to i, maxRight[i] stores max height in i to n-1
    maxLeft[0] = height[0];
    for (int i = 1; i < n; i++) {
        maxLeft[i] = max(maxLeft[i - 1], height[i]);
    }

    maxRight[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        maxRight[i] = max(maxRight[i + 1], height[i]);
    }

    int totalWater = 0;
    for (int i = 0; i < n; i++) {
        totalWater += min(maxLeft[i], maxRight[i]) - height[i];
    }

    return totalWater;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;

        vector<int> height(n);
        for (int i = 0; i < n; i++) {
            cin >> height[i];
        }

        cout << waterTrapped(height) << endl;
    }

    return 0;
}