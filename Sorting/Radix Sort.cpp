// https://www.hackerearth.com/practice/algorithms/sorting/radix-sort/tutorial/
// https://www.geeksforgeeks.org/radix-sort/

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
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

// The idea of Radix Sort is to do digit by digit sort starting from least significant digit to most significant digit.
// Radix sort uses counting sort as a subroutine to sort.

void countSort(vi &arr, int mul) {
    int n = arr.size();
    vi freq(10, 0), output(n);

    for (int i : arr) freq[(i / mul) % 10]++;
    for (int i = 1; i < 10; i++) freq[i] += freq[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[freq[(arr[i] / mul) % 10] - 1] = arr[i];
        freq[(arr[i] / mul) % 10]--;
    }

    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(vi &arr) {
    int n = arr.size();

    int mul = 1;
    int max = *max_element(arr.begin(), arr.end());

    while (max) {
        countSort(arr, mul);
        mul = mul * 10;
        max = max / 10;
    }
}

int main() {
    int n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    radixSort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
