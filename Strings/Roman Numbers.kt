// https://leetcode.com/problems/roman-to-integer?envType=study-plan-v2&envId=top-interview-150
// Given a roman numeral, convert it to an integer.
// Roman numerals are usually written largest to smallest from left to right.
// If a smaller appear before the larger, its subtracting from the larger

val map = mapOf(
    'I' to 1,
    'V' to 5,
    'X' to 10,
    'L' to 50,
    'C' to 100,
    'D' to 500,
    'M' to 1000,
)

fun romanToInt(s: String): Int {
    var n = 0

    var i = s.length - 1
    while (i >= 0) {
        if (i + 1 < s.length && map[s[i + 1]]!! > map[s[i]]!!) n -= map[s[i]]!!
        else n += map[s[i]]!!
        i--
    }

    return n
}

// https://leetcode.com/problems/integer-to-roman?envType=study-plan-v2&envId=top-interview-150
// Given an integer, convert it to a Roman numeral.
// Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:
//     If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
//     If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
//     Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.

val revMap = mapOf(
    1000 to "M",
    900 to "CM",
    500 to "D",
    400 to "CD",
    100 to "C",
    90 to "XC",
    50 to "L",
    40 to "XL",
    10 to "X",
    9 to "IX",
    5 to "V",
    4 to "IV",
    1 to "I",
)

fun intToRoman(num: Int): String {
    var n = num
    var result = ""

    revMap.forEach { (v, s) ->
        while (n >= v) {
            n -= v
            result += s
        }
    }

    return result
}
