
// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0
// Best Soln. - https://www.geeksforgeeks.org/first-non-repeating-character-using-one-traversal-of-string-set-2/
// (not for stream, but can be easily modified)

// https://www.geeksforgeeks.org/queue-based-approach-for-first-non-repeating-character-in-a-stream/ -> Good

// Basic Soln. (Not Good) -

#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

#define LN cout << __LINE__ << endl

using namespace std;

int t, n, flag;
char str[500];
int freq[26];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 0; i < 26; i++) {
            freq[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            cin >> str[i];
            freq[str[i] - 'a'] += 1;

            // Iterate through str to find 1st char with freq == 1
            flag = 0;
            for (int j = 0; j <= i; j++) {
                if (freq[str[j] - 'a'] == 1) {
                    cout << str[j] << " ";
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) cout << -1 << " ";
        }
        cout << endl;
    }

    return 0;
}

// Alternative (Better) - Instead of traversing str, we traverse freq (which has only 26 length)
// and find the char with freq == 1 and minimum index

#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

#define LN cout << __LINE__ << endl
#define iPair pair<int, int>

using namespace std;

int t, n, flag;
char str[500];
iPair freq[26];
// first stores freq and second stores index where it last appeared

int main() {
    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 0; i < 26; i++) {
            freq[i].first = 0;
            freq[i].second = INT_MAX;
        }

        for (int i = 0; i < n; i++) {
            cin >> str[i];
            freq[str[i] - 'a'].first += 1;
            freq[str[i] - 'a'].second = i;

            int minIdx = INT_MAX;
            for (int i = 0; i < 26; i++) {
                if (freq[i].first == 1 && freq[i].second < minIdx) {
                    minIdx = freq[i].second;
                }
            }

            if (minIdx == INT_MAX) {
                cout << -1 << " ";
            } else {
                cout << str[minIdx] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
