
// C++17 has <numeric> which defines gcd(int a, int b) and lcm(int a, int b).

// gcd is basically the product of the intersection of all prime factors of both.
// C++ also has inbuilt __gcd(int a, int b) function for gcd.
// euclidean algo
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }    
    return gcd(b, a%b);
}

// its basically the product of the union of all prime factors of both.
// C++17 has lcm(int a, int b) inbuilt

// this method is not applicable for more than 2 numbers.
int lcm(int a, int b) {
    return a*b/gcd(a, b);
}

// LCM of an array
void arrayLCM(vector<int> &arr) {
	long long int ans;
	ans = arr[0];
	
	for(int i : arr) {
		ans = ans*i/__gcd(ans, i);
	}	
	cout<<ans<<endl;
}

// GCD of an array
void arrayGCD(vector<int> &arr) {
	int ans = 1;

	for(int i : arr) {
		ans = __gcd(ans, i);
	}
	cout<<ans<<endl;
}


// GCD Extended Euclidean algorithm
// ax + by = GCD(a, b)
void GCDExtended(int a, int b, int &x, int &y) {
	if(a == 0) {
		x = 0;
		y = 1;	// when a is 0, GCD is 'b' so y is 1
		return b;
	}

	int x1, y1;
	int gcd = GCDExtended(b%a, a, x1, y1);

	x = y1 - (b/a)*x1;
	y = x1;

	return gcd;
}


// good gcd question
// https://www.geeksforgeeks.org/gcd-two-numbers-formed-n-repeating-x-y-times/
// takeaway - if 1st number is n repeated x times and 2nd is it reapeated y times, 
// then their gcd is n repeated gcd(x,y) times
// ex - n = 123, x = 3, y = 1 -> gcd(123123123, 123) = 123 (123 repeated gcd(1,3) = 1 times)