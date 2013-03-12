#include <iostream>
#include <cmath>
using namespace std;

//It is important to note that the possible maximum value for n is
//the lowest common divisor of a, b because it's obvious that n^2 + an + b
//is not prime since n^2, an, and b are all multiples of n
//therefore, i can conclude that a quadratic where gcd(a,b) = 1 contains more consecutive primes
int lowestCommonDivisor(int a, int b){
	if (a < 0) a*= -1; //don't want negative values when testing divisibility
	if (b < 0) b*= -1;

	for (int i = 2; i <= sqrt(a); i++){
		if (a%i==0 && b%i==0)
			return i;	
	}	
	return 1; //returns 1 when the gcd(a,b) = 1
}

//determines whether a number is prime
bool prime (int a){
	if (a<2)
		return false;

	for (int i = 2; i <= sqrt(a); i++)
		if (a%i==0) return false;
	
	return true;
}

int main(){
	int maxConsec = 0;
	int product = 0; //product of coefficients

	//iterate through all posibilities of a and b
	for (int a = -1000; a <= 1000; a++){
		for (int b = -1000; b <= 1000; b++){
			if (lowestCommonDivisor(a,b)==1){ //only check if there is no lowest divisor
				int n = 0;
				int numConsec = 0; //counter
				
				//loop until the quadratic is no longer prime
				while (prime(n*n+a*n+b)){
					numConsec++;

					//found a new maximum number of consecutive quadratic primes
					if (numConsec > maxConsec){
						maxConsec = numConsec;
						product = a*b;	
					}
					n++;
				}
			}
		}
	}

	cout << product;
	return 0;
}
