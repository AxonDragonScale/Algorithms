// https://www.interviewbit.com/problems/gray-code/
// Generate gray codes in order and print their int values

// extra - see this for how to generate actual gray codes instead of their int values -> Good
// https://www.geeksforgeeks.org/given-a-number-n-generate-bit-patterns-from-0-to-2n-1-so-that-successive-patterns-differ-by-one-bit/

// method 1 - backtracking with recursion

void util(vector<int> &ans, int &num, int n) {
    if (n == 0) {
        ans.push_back(num);
        return;
    }

    util(ans, num, n - 1);

    num = num ^ (1 << n - 1);
    util(ans, num, n - 1);
}

vector<int> Solution::grayCode(int n) {
    vector<int> ans;
    int num = 0;

    util(ans, num, n);

    return ans;
}

// method 2 - Iterative

vector<int> Solution::grayCode(int n) {
    vector<int> ans(1, 0);

    for (int i = 0; i < n; i++) {
        int curSize = ans.size();

        for (int j = curSize - 1; j >= 0; j--) {
            ans.push_back(ans[j] + (1 << i));
        }
    }

    return ans;
}