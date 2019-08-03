// https://www.interviewbit.com/problems/single-number-ii/
// https://www.geeksforgeeks.org/find-the-element-that-appears-once/

int getSingle(int arr[], int n) {
    int result = 0;

    for (int i = 0; i < 32; i++) {  // Iterate through every bit

        int count = 0;  // Find count of set bits at ith position in all array elements
        int x = (1 << i);
        for (int j = 0; j < n; j++) {
            if (arr[j] & x) count++;
        }

        // The bits with count not multiple of 3, are the bits of element with single occurrence.
        if (count % 3 != 0) result |= x;
    }

    return result;
}

int Solution::singleNumber(const vector<int> &arr) {
    int n = arr.size();

    int once = 0, twice = 0, common;
    for (int i : arr) {
        twice = twice | (once & i);  // add to twice only if it already appears in once
        once = once ^ i;             // add to once if it doesn't appear or remove it if it already appears

        common = once & twice;      // if val appears 3 times, its bits will be set in both
        once = once & (~common);    // remove
        twice = twice & (~common);  // remove
    }

    return once;
}

// code with explaination
int getSingle(int arr[], int n) {
    int ones = 0, twos = 0;

    int common_bit_mask;

    // Let us take the example of {3, 3, 2, 3} to understand this
    for (int i = 0; i < n; i++) {
        /* The expression "one & arr[i]" gives the bits that are
        there in both 'ones' and new element from arr[]. We
        add these bits to 'twos' using bitwise OR.
        Value of 'twos' will be set as 0, 3, 3 and 1 after 1st,
        2nd, 3rd and 4th iterations respectively */
        twos = twos | (ones & arr[i]);

        /* XOR the new bits with previous 'ones' to get all bits
        appearing odd number of times.
        Value of 'ones' will be set as 3, 0, 2 and 3 after 1st,
        2nd, 3rd and 4th iterations respectively */
        ones = ones ^ arr[i];

        /* The common bits are those bits which appear third time
        So these bits should not be there in both 'ones' and 'twos'.
        common_bit_mask contains all these bits as 0, so that the bits can
        be removed from 'ones' and 'twos'.
        Value of 'common_bit_mask' will be set as 00, 00, 01 and 10
        after 1st, 2nd, 3rd and 4th iterations respectively */
        common_bit_mask = ~(ones & twos);

        /* Remove common bits (the bits that appear third time) from 'ones'
        Value of 'ones' will be set as 3, 0, 0 and 2 after 1st,
        2nd, 3rd and 4th iterations respectively */
        ones &= common_bit_mask;

        /* Remove common bits (the bits that appear third time) from 'twos'
        Value of 'twos' will be set as 0, 3, 1 and 0 after 1st,
        2nd, 3rd and 4th itearations respectively */
        twos &= common_bit_mask;
    }

    return ones;
}