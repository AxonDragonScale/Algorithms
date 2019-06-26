// https://www.interviewbit.com/problems/painters-partition-problem/

using lli = long long int;

bool canPaintInTime(vector<int> &boards, int n, lli maxTime) {
    int paintersNeeded = 1;
    lli remTime = maxTime;
    for (int i = 0; i < boards.size(); i++) {
        if (remTime >= boards[i]) {  // t should be lli or overflow in multiplication
            remTime -= boards[i];
        } else {
            paintersNeeded++;
            if (boards[i] > maxTime) return false;
            remTime = maxTime - boards[i];
        }
    }

    return paintersNeeded <= n;
}

// There are n painter, that take t time to paint 1 unit of board
// boards[i] is the length of ith board
int Solution::paint(int n, int t, vector<int> &boards) {
    lli min = 0, max = 0;
    for (int i : boards) {
        max += i;  // cast to lli to avoid overflow
    }

    while (min < max) {
        lli mid = min + (max - min) / 2;

        if (canPaintInTime(boards, n, mid)) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }

    return (min * t) % 10000003;
}

// 1st try, works but no point in multipling t from the start (have to try care of more overflow situations)

using lli = long long int;

bool canPaintInTime(vector<int> &boards, lli t, int n, lli maxTime) {
    int paintersNeeded = 1;
    lli remTime = maxTime;
    for (int i = 0; i < boards.size(); i++) {
        if (remTime >= boards[i] * t) {  // t should be lli or overflow in multiplication
            remTime -= boards[i] * t;
        } else {
            paintersNeeded++;
            if (boards[i] * t > maxTime) return false;
            remTime = maxTime - boards[i] * t;
        }
    }

    return paintersNeeded <= n;
}

// There are n painter, that take t time to paint 1 unit of board
// boards[i] is the length of ith board
int Solution::paint(int n, int t, vector<int> &boards) {
    lli min = 0, max = 0;
    for (int i : boards) {
        max += (lli)i * t;  // cast to lli to avoid overflow
    }

    while (min < max) {
        lli mid = min + (max - min) / 2;

        if (canPaintInTime(boards, t, n, mid)) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }

    return min % 10000003;
}
