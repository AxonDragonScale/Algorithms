// https://www.interviewbit.com/problems/aggressive-cows/

bool isValid(vector<int> &stalls, int cows, int dist) {
    int prev = stalls[0];
    cows--;

    int i = 1;
    while (cows) {
        while (i < stalls.size() && stalls[i] - prev < dist) {
            i++;
        }

        if (i == stalls.size()) return false;
        prev = stalls[i];
        cows--;
    }

    return cows == 0;
}

int Solution::solve(vector<int> &stalls, int cows) {
    sort(stalls.begin(), stalls.end());

    int ans = 0;
    int min = 1, max = stalls.back();
    while (min <= max) {
        int mid = min + (max - min) / 2;

        if (isValid(stalls, cows, mid)) {
            ans = std::max(ans, mid);
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }

    return ans;
}
