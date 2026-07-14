// https://leetcode.com/problems/longest-common-prefix?envType=study-plan-v2&envId=top-interview-150

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Constraints:
//     1 <= strs.length <= 200
//     0 <= strs[i].length <= 200
//     strs[i] consists of only lowercase English letters if it is non-empty.

import kotlin.math.min

class Solution {

    // Simple approach
    fun longestCommonPrefix(strs: Array<String>): String {
        var result = ""

        var i = 0
        while (true) {
            if (strs[0].getOrNull(i) == null || !strs.all { it.getOrNull(i) == strs[0][i] }) return result
            result += strs[0][i]
            i++
        }

        return result
    }

    // Better approach
    fun longestCommonPrefix2(strs: Array<String>): String {
        var result = ""

        strs.sort()
        val first = strs.firstOrNull() ?: return result
        val last = strs.lastOrNull() ?: return result

        var i = 0
        while (i < min(first.length, last.length)) {
            if (first[i] != last[i]) return result
            result += first[i]
            i++
        }

        return result
    }
}
