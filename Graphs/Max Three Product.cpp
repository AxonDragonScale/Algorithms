// https://www.interviewbit.com/problems/highest-product/
// Given an array of integers, return the highest product possible by multiplying 3 numbers from the array

int Solution::maxp3(vector<int> &arr) {
    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

    for (int i : arr) {
        if (i < min1) {
            min2 = min1;
            min1 = i;
        } else if (i < min2) {
            min2 = i;
        }

        if (i > max1) {
            max3 = max2;
            max2 = max1;
            max1 = i;
        } else if (i > max2) {
            max3 = max2;
            max2 = i;
        } else if (i > max3) {
            max3 = i;
        }
    }

    return max(min1 * min2 * max1, max1 * max2 * max3);
}
