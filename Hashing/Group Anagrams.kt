// https://leetcode.com/problems/group-anagrams?envType=study-plan-v2&envId=top-interview-150
// Given an array of strings strs, group the together. You can return the answer in any order.
//
// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Explanation:
//     There is no string in strs that can be rearranged to form "bat".
//     The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
//     The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

// Approach: Simply use sorted strings as key for grouping.
fun groupAnagrams(strs: Array<String>): List<List<String>> {
    val map = mutableMapOf<String, MutableList<String>>()
    strs.forEach {
        val key = String(it.toCharArray().apply { sort() })
        map[key] = (map[key] ?: mutableListOf()).apply { add(it) }
    }

    return map.values.toList()
}

// Approach: Instead of sorting, creating key in O(n) by using char counts
fun groupAnagrams2(strs: Array<String>): List<List<String>> {
    val map = mutableMapOf<String, MutableList<String>>()
    val charCounts = IntArray(26)
    strs.forEach {
        repeat(26) { i -> charCounts[i] = 0 }
        it.forEach { c -> charCounts[c - 'a']++ }
        val key = charCounts.joinToString()
        map[key] = (map[key] ?: mutableListOf()).apply { add(it) }
    }

    return map.values.toList()
}
