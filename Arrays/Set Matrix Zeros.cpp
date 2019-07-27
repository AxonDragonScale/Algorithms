// https://www.interviewbit.com/problems/set-matrix-zeros/
// https://www.geeksforgeeks.org/a-boolean-matrix-question/

// Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0. Do it in place.

void Solution::setZeroes(vector<vector<int> > &A) {
    int rows = A.size();
    int cols = A[0].size();
    bool firstRowHasZero = false;
    bool firstColHasZero = false;

    // find if first row has a zero
    for (int j = 0; j < cols; j++) {
        if (A[0][j] == 0) {
            firstRowHasZero = true;
            break;
        }
    }

    // find if first col has zero
    for (int i = 0; i < rows; i++) {
        if (A[i][0] == 0) {
            firstColHasZero = true;
        }
    }

    // find zeros in matrix other than 1t row and col
    // mark that zero in 1st row and col (we can change it cause it will be zero anyway,
    // since we found a zero in that row or col)
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (A[i][j] == 0) {
                A[0][j] = 0;
                A[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (A[i][0] == 0 || A[0][j] == 0) {
                A[i][j] = 0;
            }
        }
    }

    if (firstRowHasZero) {
        for (int j = 0; j < cols; j++) {
            A[0][j] = 0;
        }
    }

    if (firstColHasZero) {
        for (int i = 0; i < rows; i++) {
            A[i][0] = 0;
        }
    }
}
