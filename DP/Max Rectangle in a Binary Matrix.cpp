// https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/
// https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
// https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/  -> Similar (Square)

// Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

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

// Max rectangle in Histogram method
int maxRectInHist(vector<int> &hist) {
    int n = hist.size();

    stack<int> s;
    int maxArea = 0;
    int topIndex, area;

    int i = 0;
    while (i < n) {
        if (s.empty() || hist[s.top()] <= hist[i]) {
            // If the top of stack is less than the current element push to stack
            s.push(i++);
        } else {
            // If top of stack is larger than current element, pop the top and
            // calculate the area of rectangle with that as the smallest bar
            // left is the bar after index below top, and right is i-1
            topIndex = s.top();
            s.pop();

            area = hist[topIndex] * (s.empty() ? i : (i - s.top() - 1));
            maxArea = max(area, maxArea);
        }
    }

    while (!s.empty()) {
        topIndex = s.top();
        s.pop();

        area = hist[topIndex] * (s.empty() ? n : (n - s.top() - 1));
        maxArea = max(area, maxArea);
    }

    return maxArea;
}

int maximalRectangleArea(vector<vi> &mat) {
    int r = mat.size();
    int c = mat[0].size();

    vector<int> hist(c, 0);  // hist[j] - length of vertical bar of 1s at column j
    int maxArea = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == 1) {
                hist[j]++;
            } else {
                hist[j] = 0;
            }
        }
        maxArea = max(maxArea, maxRectInHist(hist));
    }

    return maxArea;
}

// This is O(n^3) (see solution approach at interviewbit for more info)
int maximalRectangeArea(vector<vi> &mat) {
    int r = mat.size();
    int c = mat[0].size();

    int area = 0;
    vector<vi> dp(r, vi(c, 0));  // dp[i][j] stores how many continous 1s are there to left of j
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == 1) {
                if (j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i][j - 1] + 1;

                // start with this row and keep going up, use dp to get min cols for current set of rows
                int rows = 1, cols = INT_MAX;
                while ((i - rows + 1 >= 0) && mat[i - rows + 1][j] == 1) {
                    cols = min(cols, dp[i - rows + 1][j]);
                    area = max(area, rows * cols);
                    rows++;
                }
            }
        }
    }

    return area;
}

int main() {
    int r, c;
    cin >> r >> c;

    vector<vi> mat(r, vi(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }

    cout << maximalRectangeArea(mat);

    return 0;
}
