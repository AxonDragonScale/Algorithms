// https://www.interviewbit.com/problems/n3-repeat-number/
// https://www.geeksforgeeks.org/n3-repeated-number-array-o1-space/

int Solution::repeatedNumber(const vector<int> &arr) {
    int n = arr.size();

    int n1 = INT_MAX, n2 = INT_MAX, cnt1 = 0, cnt2 = 0;
    for (int i : arr) {
        if (i == n1) {
            cnt1++;
        } else if (i == n2) {
            cnt2++;
        } else if (cnt1 == 0) {
            n1 = i;
            cnt1++;
        } else if (cnt2 == 0) {
            n2 = i;
            cnt2++;
        } else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;
    for (int i : arr) {
        if (i == n1)
            cnt1++;
        else if (i == n2)
            cnt2++;
    }

    if (cnt1 > n / 3) return n1;
    if (cnt2 > n / 3) return n2;

    return -1;
}
