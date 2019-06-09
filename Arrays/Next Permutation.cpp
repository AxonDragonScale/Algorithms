// https://www.interviewbit.com/problems/next-permutation/
// https://www.geeksforgeeks.org/find-next-greater-number-set-digits/

// Its the same for lexicographic next permutation of a string.

// We can also do next_permutation(arr.begin(), arr.end())

void Solution::nextPermutation(vector<int> &arr) {
    int n = arr.size();

    int i = n - 1;
    while (i > 0 && arr[i - 1] >= arr[i]) i--;

    if (i == 0) {
        reverse(arr.begin(), arr.end());  // reversing is same as sorting here
        return;
    }

    int j = n - 1;
    while (j >= i && arr[j] <= arr[i - 1]) j--;  // least significant num thats greaeter than arr[i]
    swap(arr[i - 1], arr[j]);
    reverse(arr.begin() + i, arr.end());  // reversing is same as sorting here
}
