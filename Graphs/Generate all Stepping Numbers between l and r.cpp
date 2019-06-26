// https://www.interviewbit.com/problems/stepping-numbers/

void dfsUtil(vector<int> &ans, int n, int l, int r, int len) {
    if (n >= l && n <= r) ans.push_back(n);
    if (len == 0) return;

    if (n == 0) {
        for (int i = 1; i <= 9; i++) {
            dfsUtil(ans, i, l, r, len - 1);
        }
        return;
    }

    if (n % 10 == 0) {
        dfsUtil(ans, n * 10 + 1, l, r, len - 1);
    } else if (n % 10 == 9) {
        dfsUtil(ans, n * 10 + 8, l, r, len - 1);
    } else {
        dfsUtil(ans, n * 10 + (n % 10) - 1, l, r, len - 1);
        dfsUtil(ans, n * 10 + (n % 10) + 1, l, r, len - 1);
    }
}

vector<int> Solution::stepnum(int l, int r) {
    int len = 0, temp = r;
    while (temp) {
        len++;
        temp = temp / 10;
    }

    vector<int> ans;
    dfsUtil(ans, 0, l, r, len);

    sort(ans.begin(), ans.end());
    return ans;
}

// bool isSteppingNum(int n) {
//     int prev = n%10;
//     n = n/10;

//     while(n) {
//         if(abs(n%10 - prev) != 1) return false;
//         prev = n%10;
//         n = n/10;
//     }

//     return true;
// }

// vector<int> Solution::stepnum(int l, int r) {
//     vector<int> ans;

//     for(int i = l; i<=r; i++) {
//         if(isSteppingNum(i)) ans.push_back(i);
//     }

//     return ans;
// }
