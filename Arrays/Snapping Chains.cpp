// https://www.hackerrank.com/contests/bits-goa-test/challenges/snapper-chain-1/problem

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int c = 1; c <= t; c++) {
        int n, k;
        cin >> n >> k;

        bool isOn = true;
        for (int i = 1; i <= n; i++) {
            if (k % 2 == 0) {
                isOn = false;
            }
            k /= 2;
        }

        if (isOn) {
            cout << "Case #" << c << ": ON" << endl;
        } else {
            cout << "Case #" << c << ": OFF" << endl;
        }
    }

    // for (int c = 1; c <= t; c++) {
    //     int n, k;
    //     cin >> n >> k;

    //     if (k % (1 << n) == (1 << n) - 1) {
    //         cout << "Case #" << c << ": ON" << endl;
    //     } else {
    //         cout << "Case #" << c << ": OFF" << endl;
    //     }
    // }

    return 0;
}
