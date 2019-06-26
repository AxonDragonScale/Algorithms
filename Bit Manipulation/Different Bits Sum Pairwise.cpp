// https://www.interviewbit.com/problems/different-bits-sum-pairwise/
// https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/

// This is same as Sum of Pairwise Hamming Distance in Mathematics folder

int Solution::cntBits(vector<int> &arr) {
    int mod = 1e9 + 7;

    long long int ans = 0;
    for (int i = 0; i < 32; i++) {
        int bit0 = 0, bit1 = 0;
        for (int t : arr) {
            if ((t >> i) & 1)
                bit1++;
            else
                bit0++;
        }

        ans = (ans + 2 * (long long int)bit0 * bit1) % mod;
    }

    return ans;
}
