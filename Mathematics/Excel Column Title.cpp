// https://www.interviewbit.com/problems/excel-column-title/

string Solution::convertToTitle(int n) {
    string ans;
    while (n) {
        ans = (char)((n - 1) % 26 + 'A') + ans;
        // if n = 1 -> 0 + 'A' = 'A' and same till 'Y'.  For n = 26 -> 25 + 'A' = 'Z'
        // if we just did n%26 + 'A'-1 then for n = 26, n%26 will be 0 and give char before 'A' not 'Z'
        n = (n - 1) / 26;
        // for n = 26 we have to n/26 - 1 (cause 26/26 = 1 but it should be over) which is same as this
        // for others n-1/26 is same as n/26
    }
    return ans;
}

// string Solution::convertToTitle(int n) {
//     char temp;

//     string ans;
//     while (n) {
//         if (n % 26 == 0) {
//             temp = 'Z';
//             n = n / 26 - 1;  // ex - n = 26 then n/26 = 1 but it should be over
//         } else {
//             temp = 'A' - 1 + n % 26;
//             n = n / 26;
//         }
//         ans = temp + ans;
//     }

//     return ans;
// }
