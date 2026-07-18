// https://leetcode.com/problems/minimum-size-subarray-sum?envType=study-plan-v2&envId=top-interview-150
// Given an array of positive integers nums and a positive integer target, return the minimal length of a whose sum is greater than or equal to target.
// If there is no such subarray, return 0 instead.

fun minSubArrayLen(target: Int, nums: IntArray): Int {
    var sum = 0
    var l = 0
    var r = 0
    var min = Int.MAX_VALUE

    while (r < nums.size) {
        sum += nums[r]

        while (sum >= target) {
            min = min(min, r - l + 1)
            sum -= nums[l++]
        }

        r++
    }

    return if (min == Int.MAX_VALUE) 0 else min
}
