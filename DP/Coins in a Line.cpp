
// https://www.interviewbit.com/problems/coins-in-a-line/

int maxcoinUtil(vector<int> &A, vector< vector<int> > &dp, int start, int end) {
    if(dp[start][end] != -1) {
        return dp[start][end];
    }
    
    if(start >= end - 1) {
        return max(A[start], A[end]);
    }
    
    int option1 = maxcoinUtil(A, dp, start+2, end);
    int option2 = maxcoinUtil(A, dp, start+1, end-1);
    int option3 = maxcoinUtil(A, dp, start, end-2);
    
    // we take bcoz the other player also plays optimally
    int chooseStart = A[start] + min(option1, option2);    // we choose start and other player chooses start+1 or end whichever gives him max 
    int chooseEnd = A[end] + min(option2, option3);     // we choose end and other player chooses start ot end-1 whichever gives him max
    
    dp[start][end] = max(chooseStart, chooseEnd);
    return dp[start][end];
}

int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    vector< vector<int> > dp(n, vector<int>(n, -1));    // dp[i][j] stores max sum for coins in i to j
    
    return maxcoinUtil(A, dp, 0, n-1);
}
