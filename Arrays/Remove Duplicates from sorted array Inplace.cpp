
// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

int Solution::removeDuplicates(vector<int> &a) {
    int i = 0, j = 1;

    while (j < a.size()) {
        if (a[i] != a[j]) {
            a[i + 1] = a[j];
            i++;
            j++;
        } else {
            j++;
        }
    }

    a.resize(i + 1);
    return i + 1;
}