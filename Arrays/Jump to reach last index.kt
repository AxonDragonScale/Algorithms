// https://leetcode.com/problems/jump-game?envType=study-plan-v2&envId=top-interview-150

// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.

fun canJump(nums: IntArray): Boolean {
    var maxReach = 0
    var i = 0
    while (i < nums.size) {
        if (maxReach < i) return false
        maxReach = max(maxReach, i + nums[i])
        i++
    }

    return true
}


// https://leetcode.com/problems/jump-game-ii?envType=study-plan-v2&envId=top-interview-150

// You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.
// Each element nums[i] represents the maximum length of a forward jump from index i.
// In other words, if you are at index i, you can jump to any index between i + 1 and i + nums[i]
// Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

// Approach:
// Keep track of maxReach for each iteration, but dont jump
// Jump only when the maxReach of the previous jump point (or start) is reached.
fun jump(nums: IntArray): Int {
    if (nums.size <= 1) return 0

    var maxReach = 0
    var curReach = 0
    var jumps = 0

    var i = 0
    while (i < nums.size - 1) {
        maxReach = max(maxReach, i + nums[i])

        if (curReach == i) {
            jumps++
            curReach = maxReach

            if (curReach >= nums.size - 1) break
        }
        i++
    }

    return jumps
}
