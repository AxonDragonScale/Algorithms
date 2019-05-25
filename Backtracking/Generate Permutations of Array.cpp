
// https://www.interviewbit.com/problems/permutations/

// method 1

void util(vector<int> &arr, int start, vector<vector<int> > &ans) {
    if (start == arr.size() - 1) {
        ans.push_back(arr);
        return;
    }

    for (int i = start; i < arr.size(); i++) {
        swap(arr[start], arr[i]);
        util(arr, start + 1, ans);
        swap(arr[start], arr[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &arr) {
    vector<vector<int> > ans;
    util(arr, 0, ans);
    return ans;
}

// method 2

void util(vector<int> &arr, vector<int> &cur, vector<vector<int> > &ans, vector<bool> &used) {
    if (cur.size() == arr.size()) {
        ans.push_back(cur);
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (!used[i]) {
            cur.push_back(arr[i]);
            used[i] = true;

            util(arr, cur, ans, used);

            used[i] = false;
            cur.pop_back();
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &arr) {
    vector<vector<int> > ans;
    vector<bool> used(arr.size(), false);
    vector<int> cur;

    util(arr, cur, ans, used);

    return ans;
}
