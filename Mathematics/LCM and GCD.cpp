
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

// Iterative GCD
int gcd(int a, int b) {
	int temp;

	while(b != 0) {
		temp = b;
		b = a%b;
		a = temp;
	}

	return a;
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
