// https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/

// Method 1 - If m is prime, then its num^(m-2)
int power(int a, int b, int m) {
    if (b == 0) return 1;

    int p = power(a, b / 2, m) % m;
    p = (p * p) % m;
    return (b % 2 == 0) ? p : (a * p) % m;
}

int modInverse(int a, int m) {
    if (__gcd(a, m) != 1) {
        cout << "a and m not co-prime. No Inverse." << endl;
        return -1;
    } else {
        return power(a, m - 2, m);
    }
}

// Method 2 - Using Extended Euclid
int gcdExtended(int a, int b, int &t, int &s) {
    if (a == 0) {
        t = 0;
        s = 1;
        return b;
    }

    int t1, s1;
    int g = gcdExtended(b % a, a, t1, s1);

    t = s1 - (b / a) * t1;
    s = t;
}

void modInverse(int a, int m) {
    int t, s;
    int g = gcdExtended(a, m, t, s);

    if (g != 1) {
        cout << "a and m not co-prime. No Inverse." << endl;
    } else {
        return (t % m + m) % m;
    }
}