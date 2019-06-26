// https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/

int Solution::hammingDistance(const vector<int> &arr) {
    int n = arr.size();

    long long int ans = 0;
    int mod = 1000000007;
    for (int k = 0; k < 31; k++) {
        int mask = 1 << k;
        long long cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] & mask)
                cnt1++;
            else
                cnt0++;
        }

        ans = (ans + 2 * (cnt0 * cnt1) % mod) % mod;
    }

    return ans;
}

// int hammingDist(int a, int b) {
//     int cnt = 0;
//     while(a != 0 || b != 0) {
//         if((a & 1) != (b & 1)) cnt++;
//         a = a>>1; b = b>>1;

//     }
//     return cnt;
// }

// int Solution::hammingDistance(const vector<int> &arr) {
//     int n = arr.size();

//     int mod = 1e9 + 7;
//     int ans = 0;
//     for(int i = 0; i<n; i++) {
//         for(int j = i; j<n; j++) {
//             if(i != j) {
//                 ans = (ans + 2*hammingDist(arr[i], arr[j]))%mod;
//             } else {
//                 ans = (ans + hammingDist(arr[i], arr[j]))%mod;
//             }
//         }
//     }

//     return ans;
// }
