// https://leetcode.com/problems/valid-sudoku?envType=study-plan-v2&envId=top-interview-150
// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//     Each row must contain the digits 1-9 without repetition.
//     Each column must contain the digits 1-9 without repetition.
//     Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

fun isValidSudoku(board: Array<CharArray>): Boolean {
    val rows = Array(9) { BooleanArray(9) }
    val cols = Array(9) { BooleanArray(9) }
    val boxes = Array(9) { BooleanArray(9) }
    var n = 0

    for (i in 0 until 9) {
        for (j in 0 until 9) {
            if (board[i][j] == '.') continue

            n = board[i][j] - '1'
            var boxIndex = (i / 3) * 3 + (j / 3)

            if (rows[i][n] || cols[j][n] || boxes[boxIndex][n]) return false

            rows[i][n] = true
            cols[j][n] = true
            boxes[boxIndex][n] = true
        }
    }

    return true
}

fun isValidSudoku2(board: Array<CharArray>): Boolean {
    val seen = mutableSetOf<Char>()
    val seen2 = mutableSetOf<Char>()

    for (i in 0..8) {
        seen.clear()
        seen2.clear()
        for (j in 0..8) {
            if (board[i][j] != '.') {
                if (board[i][j] in seen) return false
                seen.add(board[i][j])
            }
            if (board[j][i] != '.') {
                if (board[j][i] in seen2) return false
                seen2.add(board[j][i])
            }
        }
    }

    for (i in 0..6 step 3) {
        for (j in 0..6 step 3) {
            seen.clear()

            for (r in i..i + 2) {
                for (c in j..j + 2) {
                    if (board[r][c] != '.') {
                        if (board[r][c] in seen) return false
                        seen.add(board[r][c])
                    }
                }
            }
        }
    }

    return true
}
