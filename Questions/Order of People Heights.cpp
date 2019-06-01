// http://qa.geeksforgeeks.org/3974/qa.geeksforgeeks.org/3974/determine-the-actual-order-heights-google.html
// https://amortizedminds.wordpress.com/2016/08/25/order-of-people-height-interviewbit/

// https://www.interviewbit.com/problems/order-of-people-heights/

// Method 1 - How does this work
vector<int> Solution::order(vector<int> &heights, vector<int> &inFronts) {
    int n = heights.size();
    vector<int> ans(n, -1);

    vector<int> pos(n);
    map<int, int> m;  // map automatically sorts so you dont need to
    for (int i = 0; i < n; i++) {
        m[heights[i]] = inFronts[i];
        pos[i] = i;
    }

    for (pair<int, int> p : m) {
        int height = p.first;
        int inFront = p.second;

        int idx = pos[inFront];
        ans[idx] = height;

        pos.erase(pos.begin() + inFront);
    }

    return ans;
}

// TODO - IMP - Do segment tree method