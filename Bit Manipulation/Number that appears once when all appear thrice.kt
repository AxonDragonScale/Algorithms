// https://leetcode.com/problems/single-number-ii?envType=study-plan-v2&envId=top-interview-150
// Given an integer array nums where every element appears three times except for one, which appears exactly once.
// Find the single element and return it.

fun singleNumber(nums: IntArray): Int {
    var ones = 0
    var twos = 0

    nums.forEach { n ->
        ones = ones xor (n and twos.inv())  // xor n and ones if n not in twos
        twos = twos xor (n and ones.inv())  // xor n and twos if n not in ones
    }

    // Suppose a number n comes 3 times
    // ones:
    // 0 xor n = n -> n xor n = 0 -> 0 xor 0 = 0 (xor 0 3rd time since n already in twos)
    // twos:
    // 0 xor 0 = 0 -> 0 xor n = 0 -> n xor n = 0 (xor 0 1st time sinze n already in ones)

    return ones
}
