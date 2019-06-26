// https://www.interviewbit.com/problems/integer-to-roman/

string Solution::intToRoman(int n) {
    string ans;

    vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> str = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int i = 0;
    while (i < val.size() && n > 0) {
        while (n >= val[i]) {
            ans += str[i];
            n -= val[i];
        }

        i++;
    }

    return ans;
}
