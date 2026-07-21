// https://leetcode.com/problems/zigzag-conversion?envType=study-plan-v2&envId=top-interview-150
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows

fun convert(s: String, numRows: Int): String {
    if (numRows <= 1 || numRows >= s.length) return s

    val rows = MutableList(numRows) { StringBuilder() }

    var i = 0
    var curRow = 0
    var dir = true  // true is up the column. (Start with true bcoz it will be reversed at index 0)
    while (i < s.length) {
        rows[curRow].append(s[i])

        // Iterate column by column over the rows.
        // Go down the column. Then go up the next column. Then again down the next column ...
        if (curRow == 0 || curRow == numRows - 1) dir = !dir
        if (dir) curRow-- else curRow++
        i++
    }

    return rows.joinToString("") { it.toString() }
}
