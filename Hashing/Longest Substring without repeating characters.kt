// https://leetcode.com/problems/longest-substring-without-repeating-characters?envType=study-plan-v2&envId=top-interview-150
// Given a string s, find the length of the longest without duplicate characters.

// Approach: Sliding window that iterates using right pointer.
// If next char is already in substring, move left pointer forward until its not.
fun lengthOfLongestSubstring(s: String): Int {
    var l = 0
    var r = 0
    var max = 0
    val seen = mutableSetOf<Char>()

    while (r < s.length) {
        while (l < r && seen.contains(s[r])) {
            seen.remove(s[l])
            l++
        }

        seen.add(s[r])
        max = max(max, r - l + 1)
        r++
    }

    return max
}

// Approach: Same as above, just instead of set, use a map to store latest index for each char.
// If new char already exists, then move left pointer to just after it
fun lengthOfLongestSubstring2(s: String): Int {
    var l = 0
    var r = 0
    var max = 0
    val indexMap = mutableMapOf<Char, Int>()

    while (r < s.length) {
        if (indexMap[s[r]] ?: -1 >= l) {
            l = indexMap[s[r]]!! + 1
        }

        indexMap[s[r]] = r
        max = max(max, r - l + 1)
        r++
    }

    return max
}
