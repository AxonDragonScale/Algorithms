// https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/
// https://www.interviewbit.com/problems/matrix-median/

// Algorithm:
// First we find the minimum and maximum elements in the matrix. Minimum element can be easily found by comparing the
// first element of each row, and similarly the maximum element can be found by comparing the last element of each row.
// Then we use binary search on our range of numbers from minimum to maximum, we find the mid of the min and max, and
// get count of numbers less than our mid. And accordingly change the min or max. For a number to be median, there
// should be (r*c)/2 numbers smaller than that number. So for every number, we get the count of numbers less than that
// by using upper_bound() in each row of matrix, if it is less than the required count, the median must be greater than
// the selected number, else the median must be less than or equal to the selected number.

int matrixMedian(vector<vector<int>> &mat) {
    int r = mat.size();
    int c = mat[0].size();

    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < r; i++) {
        if (mat[i][0] < mn) mn = mat[i][0];
        if (mat[i][c - 1] > mx) mx = mat[i][c - 1];
    }

    int neededPos = (r * c + 1) / 2;
    while (mn < mx) {
        int mid = mn + (mx - mn) / 2;

        // pos basically gives count of elements smaller than mid
        int pos = 0;
        for (int i = 0; i < r; i++) {
            pos += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        }

        if (pos < neededPos) {
            mn = mid + 1;
        } else {
            mx = mid;
        }
    }

    return mn;
}