
// https://www.interviewbit.com/problems/spiral-order-matrix-i/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    
    vector<int> ans;
    
    int t, b; // for row top and bottom limits
    int l, r; // for column left and right limits
    int dir = 0; // 0 - left to right, 1 - top to bottom, 2 - right to left, 4 - bottom to top
    
    t = 0;
    b = A.size() - 1;
    l = 0;
    r = A[0].size() - 1;
    while(t <= b && l <= r) {
        if(dir == 0) {
            for(int i = l; i<=r; i++) {
                ans.push_back(A[t][i]);
            }
            t++;
        } else if(dir == 1) {
            for(int i = t; i<=b; i++) {
                ans.push_back(A[i][r]);
            }
            r--;
        } else if(dir == 2) {
            for(int i = r; i>=l; i--) {
                ans.push_back(A[b][i]);
            }
            b--;
        } else if(dir == 3) {
            for(int i = b; i>=t; i--) {
                ans.push_back(A[i][l]);
            }
            l++;
        }
        
        dir = (dir+1)%4;
    }
    return ans;
}
