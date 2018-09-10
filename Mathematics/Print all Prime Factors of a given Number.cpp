
// https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/

void printAllPrimeFactors(int n) {
	multiset<int> primeFactors;

	while(n%2 == 0) {	
		primeFactors.insert(2);
		n = n/2;
	}

	for(int i = 3; i<=sqrt(n); i+=2) {
		while(n%i == 0) {
			primeFactors.insert(i);
			n = n/i;
		}
	}

	// if n itself is a prime number > 2
	if(n>2) {
		primeFactors.insert(n);
	}

	for(int i : primeFactors) {
		cout<<i<<" ";
	}
	cout<<endl;
}


// https://www.geeksforgeeks.org/find-largest-prime-factor-number/
void largestPrimeFactor(int n) {
	int largest = -1;

	while(n%2 == 0) {
		largest = 2;
		n = n/2;
	}

	for(int i = 3; i<sqrt(n); i+=2) {
		if(n%i == 0) {
			largest = i;
			n = n/i;
		}
	}

	if(n>2) {
		largest = n;
	}

	cout<<largest<<endl;
}