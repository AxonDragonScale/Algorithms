// https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/
// https://www.geeksforgeeks.org/find-the-smallest-binary-digit-multiple-of-given-number/

string Solution::multiple(int n) {
    vector<bool> vis(n, false);
    vector<int> val(n), parent(n);
    queue<int> q;

    int temp = 1 % n;
    vis[temp] = true;
    val[temp] = 1;  // val stores whether 0 or 1 was pushed
    q.push(temp);

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp == 0) {
            string ans;
            ans += (val[temp] + '0');
            temp = parent[temp];
            while (temp != 0) {
                ans += (val[temp] + '0');
                temp = parent[temp];
            }

            reverse(ans.begin(), ans.end());
            return ans;
        }

        int child = (temp * 10) % n;  // left child (0)
        if (!vis[child]) {
            vis[child] = true;
            q.push(child);
            parent[child] = temp;
            val[child] = 0;
        }

        child = (child + 1) % n;  // right child (1)
        if (!vis[child]) {
            vis[child] = true;
            q.push(child);
            parent[child] = temp;
            val[child] = 1;
        }
    }
}

// gfg
int mod(string &temp, int n) {
    int r = 0;

    for (char i : temp) {
        r = r * 10 + (i - '0');
        r = r % n;
    }

    return r;
}

string Solution::multiple(int n) {
    unordered_set<int> vis;
    queue<string> q;
    q.push("1");

    while (!q.empty()) {
        string temp = q.front();
        q.pop();

        int rem = mod(temp, n);
        if (rem == 0) return temp;

        if (vis.find(rem) == vis.end()) {
            vis.insert(rem);
            q.push(temp + "0");
            q.push(temp + "1");
        }
    }
}
