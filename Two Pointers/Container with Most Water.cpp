// https://www.interviewbit.com/problems/container-with-most-water/

// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
// 'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.

int Solution::maxArea(vector<int> &arr) {
    int n = arr.size();
    if (n < 2) return 0;

    int area = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        area = max(area, min(arr[l], arr[r]) * (r - l));
        if (arr[l] < arr[r])
            l++;
        else
            r--;
    }

    return area;
}
