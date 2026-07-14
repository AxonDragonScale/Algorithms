// https://leetcode.com/problems/3sum?envType=study-plan-v2&envId=top-interview-150

// Only difference from `Triplets with Sum Zero.cpp` is that duplicates are not allowed

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

// Example 2:
// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.

// Example 3:
// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.


// Two Pointer Approach
fun threeSum(nums: IntArray): List<List<Int>> {
    nums.sort()
    val n = nums.size

    val result = mutableListOf<List<Int>>()
    var i = 0
    var j = i + 1
    var k = n - 1
    var t = 0
    while (i < n - 2) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            i++; continue; }
        // Optimization: skip iteration if nums[i] > 0, since for sorted triplet, the lowest must <= 0 for 0 sum

        j = i + 1
        k = n - 1
        while (j < k) {
            t = nums[i] + nums[j] + nums[k]
            when {
                t == 0 -> {
                    result.add(listOf(nums[i], nums[j], nums[k])) å
                            j++
                    k--

                    while (nums[j] == nums[j - 1] && j < k) j++
                }

                t > 0 -> k--
                t < 0 -> j++
            }
        }

        i++
    }

    return result
}
