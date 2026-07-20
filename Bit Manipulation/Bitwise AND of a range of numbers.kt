// https://leetcode.com/problems/bitwise-and-of-numbers-range?envType=study-plan-v2&envId=top-interview-150
// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

fun rangeBitwiseAnd(left: Int, right: Int): Int {
    var count = 0

    var l = left
    var r = right

    // Keep removing the rightmost bit until both become equal
    while (l != r) {
        l = l shr 1
        r = r shr 1
        count++
    }

    // Add the same number of 0s at the end
    return l shl count
}
