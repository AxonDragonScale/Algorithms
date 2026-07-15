// https://leetcode.com/problems/reverse-bits/description/?envType=study-plan-v2&envId=top-interview-150

// Reverse bits of a given 32 bits signed integer.

// Approach: Similar to how you would do it for a base-10 number
// Iterate over the number, get the last digit (% 10), append to result (res * 10 + digit), remove last digit from num ( / 10)
// This is the same but with 2 instead of 10
fun reverseBits(n: Int): Int {
    var result = 0
    var n = n
    for (i in 0 until 32) {
        result = result shl 1
        result = result or (n and 1)
        n = n ushr 1
    }

    return result
}


// Approach: Divide in half, swap the halfs -> reverse the havles -> reversed number
// Ex- 101011 -> 101 - 011 -> 011 - 101 -> 110 - 101 -> 110101
fun reverseBits2(n: Int): Int {
    return rev(n, 32)
}

fun rev(n: Int, len: Int): Int {
    if (len == 1) return n

    val halfLen = len shr 1             // len / 2
    val halfMask = (1 shl halfLen) - 1  // First half 0s and second half 1s

    val left = n ushr halfLen
    val right = n and halfMask

    val swapRevLeft = rev(right, halfLen)
    val swapRevRight = rev(left, halfLen)

    return (swapRevLeft shl halfLen) or swapRevRight
}
