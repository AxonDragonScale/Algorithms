// https://www.interviewbit.com/problems/power-of-two-integers/
// https://www.geeksforgeeks.org/check-if-a-number-can-be-expressed-as-ab-set-2/

int Solution::isPower(int n) {
    if (n == 1) return 1;

    for (int i = 2; i * i <= n; i++) {
        double lognbasei = log(n) / log(i);  // if lognbasei is an exact int then n is a power of i
        if (lognbasei - (int)lognbasei <= 0.00000001) return 1;
    }

    return 0;
}

// int Solution::isPower(int n) {
//     if(n==1) return 1;

//     for(int i = 2; i<sqrt(n)+1; i++) {
//         int temp = n;
//         if(temp%i == 0) {
//             int cnt = 0;
//             while(temp % i == 0) {
//                 temp = temp/i;
//                 cnt++;
//             }

//             if(temp == 1 && cnt > 1) return 1;
//         }
//     }

//     return 0;
// }