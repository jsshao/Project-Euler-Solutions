#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//Note that all numbers > 10 that are circular ONLY have digits of 1, 3, 7, 9 because
//2,4,6,8,5,0 makes it divisible by 2 or 5 so we ignore those cases

//determines if number is prime
bool isPrime(int n){
	for (int i = 2; i <= sqrt(n); i++)
		if (n%i==0) return 0;
	return 1;
}

//determines number of digits
int digits(int n){
	int a = 0;
	while (n>0){
		a++;
		n/=10;
	}
	return a;
}

//determines if number is a circular prime
bool isCircle(int n){
	for (int i = 0; i < digits(n); i++){
		int temp = n%10;
		n/=10;
		n+=temp*pow(10, digits(n));
		if (!isPrime(n)) return 0;
	} 	
	return 1;
}

int main(){
	int counter = 4; //number of 1 digit circulars
	int temp[] = {1,3,7,9}; //temp array to initialize a vector in C++98
	vector <int> cirPrimes(temp, temp+sizeof(temp)/sizeof(temp[0]));
	vector <int> newPrimes; //temporary vector to hold the next digit potential circular primes

	//Run 5 times to get to 6 digits
	for (int j = 0; j < 5; j++){
		//Find all next permutations of 1,3,7,9 by concatenating 1,3,7,9 as the leading digit
		//onto ALL previous permutations of 1,3,7,9
		for (int i = 0; i < cirPrimes.size(); i++){
			newPrimes.push_back(1*pow(10,digits(cirPrimes[i])) + cirPrimes[i]);
			newPrimes.push_back(3*pow(10,digits(cirPrimes[i])) + cirPrimes[i]);
			newPrimes.push_back(7*pow(10,digits(cirPrimes[i])) + cirPrimes[i]);
			newPrimes.push_back(9*pow(10,digits(cirPrimes[i])) + cirPrimes[i]);
		}
		
		//Keeping track of how many new circular primes were found
		for (int i = 0; i < newPrimes.size();i++)
			if (isCircle(newPrimes[i])) counter++;
		
		//Reinitialize and reset the vector containers
		cirPrimes.swap(newPrimes);
		newPrimes.clear();
	}
	cout << counter;
	return 0;
}
