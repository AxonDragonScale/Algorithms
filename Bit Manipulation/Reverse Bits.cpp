// https://www.interviewbit.com/problems/reverse-bits/

unsigned int Solution::reverse(unsigned int n) {
    for (int i = 0; i < 16; i++) {
        bool bitI = (n >> i) & 1;
        bool bitNI = (n >> (31 - i)) & 1;

        if (bitI) {
            n = n | (1 << (31 - i));  // set
        } else {
            n = n & ~(1 << (31 - i));  // clear
        }

        if (bitNI) {
            n = n | (1 << i);
        } else {
            n = n & ~(1 << i);
        }
    }

    return n;
}
