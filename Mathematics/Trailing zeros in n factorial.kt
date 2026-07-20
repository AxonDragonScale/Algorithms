// https://leetcode.com/problems/factorial-trailing-zeroes?envType=study-plan-v2&envId=top-interview-150
// Given an integer n, return the number of trailing zeroes in n!.

fun trailingZeroes(n: Int): Int {
    var n = n
    var count = 0

    while (n > 0) {
        n = n / 5
        count += n  // There are n/5 fives between n/5 and n
    }

    return count
}
