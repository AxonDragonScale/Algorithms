// https://www.interviewbit.com/problems/seats/
// http://qa.geeksforgeeks.org/4088/qa.geeksforgeeks.org/4088/what-are-the-total-number-minimum-hops-jumps-for-arrangement.html

int Solution::seats(string s) {
    int n = s.size();
    int m = 10000003;

    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x') {
            pos.push_back(i);
        }
    }

    n = pos.size();
    if (n <= 0) return 0;
    int median = pos[n / 2];

    int moves = 0;
    int l = median - 1, r = median + 1;
    int i = n / 2 - 1, j = n / 2 + 1;
    while (i >= 0 || j < n) {
        if (i >= 0) {
            moves += l - pos[i];
            l--;
            i--;
        }

        if (j < n) {
            moves += pos[j] - r;
            j++;
            r++;
        }

        moves = moves % m;
    }

    return moves;
}
