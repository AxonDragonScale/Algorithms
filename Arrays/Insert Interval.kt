// https://leetcode.com/problems/insert-interval?envType=study-plan-v2&envId=top-interview-150

// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti.
// You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
// Return intervals after the insertion.
// Note that you don't need to modify intervals in-place. You can make a new array and return it.

// Example 1:
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]

// Example 2:
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

fun insert(intervals: Array<IntArray>, new: IntArray): Array<IntArray> {
    val result = mutableListOf<IntArray>()
    var i = 0

    while (i < intervals.size && intervals[i][1] < new[0]) {
        result.add(intervals[i])
        i++
    }

    while (i < intervals.size && new[1] >= intervals[i][0]) {
        new[0] = min(new[0], intervals[i][0])
        new[1] = max(new[1], intervals[i][1])
        i++
    }
    result.add(new)

    while (i < intervals.size) {
        result.add(intervals[i])
        i++
    }

    return result.toTypedArray()
}
