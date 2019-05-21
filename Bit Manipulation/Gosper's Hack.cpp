// Gosper’s hack is a technique to get the next number with same number of bits set.
// Gosper’s Hack iterates through all n-bit values that have k bits set to 1, from lowest to highest.

// http://programmingforinsomniacs.blogspot.com/2018/03/gospers-hack-explained.html

void GospersHack(int k, int n) {
    int set = (1 << k) - 1;
    int limit = (1 << n);
    while (set < limit) {
        doStuff(set);  // something you want to execute for the set

        // Gosper's hack:
        int c = set & -set;  //  x & -x yields the least significant/rightmost 1-bit in x.
        int r = set + c;
        set = (((r ^ set) >> 2) / c) | r;
    }
}
