#include <iostream>
#include <cmath>

using namespace std;

//Check for prime factors
bool isPrime(int n){
	if (n==0 || n==1) return false; //trivially not prime
	
	for (int i = 2; i <= sqrt(n); i++)
		if (n%i==0) 
			return false;
	return true;
}

//Test primality from the right by using integer division
bool isRTrunc(int n){
	while (n){
		if (!isPrime(n))
			return false;
		n/=10;	
	}
	return true;
}

//Test primality from the left by using modular arithmetic
bool isLTrunc(int n){
	for (int i = 1; i <= log10(n)+1; i++){
		if (!isPrime(n%((int)pow(10,i))))
			return false;
	}
	return true;
}

int main(){
	int counter = 0, sum = 0;
	
	int i = 23; //the first truncatable prime by inspection
	while (counter < 11){
		if (isRTrunc(i) && isLTrunc(i)){
			sum += i;
			counter ++;
		}
		i++;
	}
	cout << sum;
	return 0;
}
