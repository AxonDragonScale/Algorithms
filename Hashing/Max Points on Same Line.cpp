// https://www.geeksforgeeks.org/count-maximum-points-on-same-line/
// https://www.interviewbit.com/problems/points-on-the-straight-line/

int Solution::maxPoints(vector<int> &x, vector<int> &y) {
    int n = x.size();
    if (n <= 2) return n;

    map<pair<int, int>, int> hashMap;  // key is slope info, value is count
    int ans = 0;
    for (int i = 0; i < n; i++) {
        hashMap.clear();
        int same = 0, curMax = 0, vertical = 0;

        // find max points starting from point i that are on same line (same slope with i)
        for (int j = i + 1; j < n; j++) {
            int ydiff = y[j] - y[i], xdiff = x[j] - x[i];
            if (xdiff == 0 && ydiff == 0) {
                same++;
                continue;
            } else if (xdiff == 0) {
                vertical++;
            } else {
                if (xdiff < 0) {
                    ydiff *= -1;
                    xdiff *= -1;
                }

                int gcd = __gcd(abs(ydiff), xdiff);
                hashMap[{ydiff / gcd, xdiff / gcd}]++;
                curMax = max(curMax, hashMap[{ydiff / gcd, xdiff / gcd}]);
            }

            curMax = max(curMax, vertical);
        }

        curMax += same + 1;  // 1 for point i
        ans = max(ans, curMax);
    }

    return ans;
}

int Solution::maxPoints(vector<int> &x, vector<int> &y) {
    int n = x.size();
    if (n <= 2) return n;

    map<pair<int, int>, int> hashMap;  // key is slope info, value is count
    int ans = 0;
    for (int i = 0; i < n; i++) {
        hashMap.clear();
        int same = 0, curMax = 0;

        for (int j = i + 1; j < n; j++) {
            int ydiff = y[j] - y[i], xdiff = x[j] - x[i];
            if (xdiff == 0 && ydiff == 0) {
                same++;
                continue;
            }

            if (xdiff < 0) {
                ydiff *= -1;
                xdiff *= -1;
            } else if (xdiff == 0)
                ydiff = abs(ydiff);  // vertical line upward and downward are same

            int gcd = __gcd(abs(ydiff), xdiff);
            hashMap[{ydiff / gcd, xdiff / gcd}]++;
            curMax = max(curMax, hashMap[{ydiff / gcd, xdiff / gcd}]);
        }

        curMax += same + 1;  // 1 for point i
        ans = max(ans, curMax);
    }

    return ans;
}
