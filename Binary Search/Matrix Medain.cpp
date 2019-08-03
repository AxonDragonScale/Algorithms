// https://www.interviewbit.com/problems/matrix-median/

using iPair = pair<int, int>;

int Solution::findMedian(vector<vector<int>> &mat) {
    int r = mat.size();
    int c = mat[0].size();

    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < r; i++) {
        if (mat[i][0] < mn) mn = mat[i][0];
        if (mat[i][c - 1] > mx) mx = mat[i][c - 1];
    }

    int neededPos = (r * c + 1) / 2;
    while (mn < mx) {
        int mid = mn + (mx - mn) / 2;

        // pos basically gives count of elements smaller than mid
        int pos = 0;
        for (int i = 0; i < r; i++) {
            pos += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        }

        if (pos < neededPos) {
            mn = mid + 1;
        } else {
            mx = mid;
        }
    }

    return mn;
}

// Works but uses O(n) space

// int Solution::findMedian(vector<vector<int>> &mat) {
//     int n = mat.size();
//     int m = mat[0].size();

//     priority_queue<iPair, vector<iPair>, greater<iPair>> minHeap;
//     for(int i = 0; i<n; i++) {
//         minHeap.push({mat[i][0], i});
//     }

//     vector<int> idx(n, 1);

//     for(int i = 0; i<(m*n-1)/2; i++) {
//         iPair temp = minHeap.top(); minHeap.pop();
//         if(idx[temp.second] < m)
//             minHeap.push({mat[temp.second][idx[temp.second]++], temp.second});
//     }

//     int median = 0;
//     if(m*n % 2 == 0) {
//         iPair temp1 = minHeap.top(); minHeap.pop();
//         iPair temp2 = minHeap.top(); minHeap.pop();
//         median = (temp1.first + temp2.first)/2;
//         return median;
//     } else {
//         iPair temp = minHeap.top(); minHeap.pop();
//         return temp.first;
//     }
// }
