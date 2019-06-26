// https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/
// https://www.geeksforgeeks.org/find-the-largest-rectangle-of-1s-with-swapping-of-columns-allowed/  -> GOOD

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

// Easier
int maxAreaRectangle(vector<vector<int>> &mat) {
    int r = mat.size();
    int c = mat[0].size();

    // in an aux matrix at i,j store number of consecutive 1s in column j starting at i and above it
    vector<vector<int>> aux(r, vector<int>(c));
    for (int j = 0; j < c; j++) {
        aux[0][j] = mat[0][j];
        for (int i = 1; i < r; i++) {
            aux[i][j] = (mat[i][j] == 0) ? 0 : aux[i - 1][j] + 1;
        }
    }

    for (int i = 0; i < r; i++) {
        // sort each row - Here we use counting sort bcoz any number can't be more than r (we can also just use sort)
        vector<int> count(r + 1, 0);
        for (int j = 0; j < c; j++) count[aux[i][j]]++;

        int col = 0;
        for (int k = r; k >= 0; k--) {
            for (int cnt = 0; cnt < count[k]; cnt++) {
                aux[i][col++] = k;
            }
        }
    }

    int area = 0, maxArea = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            area = (j + 1) * aux[i][j];
            maxArea = max(area, maxArea);
        }
    }

    return maxArea;
}

int maxAreaRectangle(vector<vector<int>> &mat) {
    int r = mat.size();
    int c = mat[0].size();

    // in an aux matrix at i,j store number of consecutive 1s in column j starting at i and above it
    vector<vector<int>> aux(r, vector<int>(c));
    for (int j = 0; j < c; j++) {
        aux[0][j] = mat[0][j];
        for (int i = 1; i < r; i++) {
            aux[i][j] = (mat[i][j] == 0) ? 0 : aux[i - 1][j] + 1;
        }
    }

    int maxArea = 0;
    for (int i = 0; i < r; i++) {
        vector<int> count(r + 1, 0);
        for (int j = 0; j < c; j++) count[aux[i][j]]++;

        int width = 0;  // h is height
        for (int h = r; h >= 0; h--) {
            width += count[h];  // 0 if no height never h
            maxArea = max(maxArea, width * h);
        }
    }

    return maxArea;
}

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> mat(r, vi(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }

    cout << maxAreaRectangle(mat) << endl;
    return 0;
}
