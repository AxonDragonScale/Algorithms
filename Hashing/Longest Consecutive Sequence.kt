// https://leetcode.com/problems/longest-consecutive-sequence?envType=study-plan-v2&envId=top-interview-150

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// Example 1:
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

fun longestConsecutive(nums: IntArray): Int {
    val set = nums.toSet()

    var max = 0
    var cur = 0
    for (i in set) {
        if (i - 1 !in set) {  // Num before it not present. Meaning this is first item in sequence
            cur = i + 1
            while (cur in set) { cur++ }
            max = max(max, cur - i)
        }
    }

    return max
}
