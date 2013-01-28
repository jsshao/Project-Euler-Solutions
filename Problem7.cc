#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n){
	for (int i = 2; i <= sqrt(n); i++)
		if (n%i==0) return 0;
	return 1; 
}

int main(){
	//Research Sieve of Erastothenes for more prime number algorithm
	//Since the bound on the 10001th prime is not easily calculated, I will brute force this
	int counter = 0;
	int iterator = 2;

	while (counter != 10001){
		if (isPrime(iterator)) counter ++;
		iterator++;
	}
	
	cout << iterator - 1;
	return 0;
}
