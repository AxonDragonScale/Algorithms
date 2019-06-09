// https://www.interviewbit.com/problems/largest-coprime-divisor/
// https://www.geeksforgeeks.org/largest-number-divides-x-co-prime-y/

// You are given two positive numbers A and B. You need to find the maximum valued integer X such that:
// 1. X divides A i.e. A % X = 0
// 2. X and B are co-prime i.e. gcd(X, B) = 1

// If we remove all common factors from A, then the resulting number will divide A
// and it wont have any common factor with B, so coprime.
int Solution::cpFact(int A, int B) {
    while (__gcd(A, B) != 1) {
        A = A / __gcd(A, B);
    }
    return A;
}