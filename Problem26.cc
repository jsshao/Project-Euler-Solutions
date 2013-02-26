#include <iostream>
#include <vector>

using namespace std;

//THIS PROBLEM IS VERY MATHEMATICALLY INTENSIVE!!!! DO NOT ATTEMPT TO READ THE CODE UNTIL
//YOU HAVE A FAIR UNDERSTANDING OF NUMBER THEORY

/*
THEOREM 1:
Let p be a prime number, q be the period of repeating decimals of 1/p
then q is the smallest positive integer such that 10^q = 1 (mod p)

In other words, q is the order of 10 modulo p.

THEOREM 2:
Furthermore, if p is a prime number, the period for 1/(p^n) is p^(n-1)q where q is the 
period for 1/p

THEOREM 3:
Also, let f(p) be the function that produces the period of repeating decimals of prime p.
Let a, b be prime numbers, then
f(a*b) = lcm(f(a), f(b))

However, in my program, I only considered theorem 2 because for a large prime < 1000,
p^(n-1)q will be greater than the lcm(f(a), f(b)) by inspection.

Therefore, I only considered multiples of primes and ignored all composite numbers of distinct primes
*/


//returns the period stated in THEOREM 1
int OrderOf10 (int modulo){
	int temp = 10, counter = 1;
	
	while (temp!=1){
		temp = (temp*10)%modulo;
		counter++;
	}

	return counter;
}

//created my own exponent function because pow() has odd issues
int exponent (int a, int b){
	int answer = a;
	for (int i = 1; i < b; i++)
		answer *= a;

	return answer;
}

int main(){
	bool prime[1000] = {0}; //0 is prime, 1 is composite
	int repeatedDigits[1000] = {0}; //the ith value is the number of repeated digits of i

	//sieves algorithm for prime number generation
	for (int i = 2; i < 1000; i++){
		if (prime[i] == 0){
			int counter = 2*i;
			while (counter < 1000){
				prime[counter] = 1;
				counter += i;
			}
		}
	}

	//record repeated digits of JUST prime numbers first
	for (int i = 2; i < 1000; i++)
		if (prime[i] == 0 && i != 2 && i != 5)
			repeatedDigits[i] = OrderOf10(i);

	//record repeated digits of powers of prime numbers
	for (int i = 2; i < 1000; i++){
		if (prime[i] ==0 && i != 2 && i != 5){
			int counter = 2;
			while (exponent(i,counter) < 1000){
				//Recall from THEOREM 2: period of 1/p^n = p^(n-1)q 
				repeatedDigits[exponent(i,counter)] = i*repeatedDigits[exponent(i,counter-1)];
				counter ++;
			}	
		}
	}	
	
	//find the number with the greatest period
	int max = 2;
	for (int i = 2; i < 1000; i++){
		if (repeatedDigits[i] > repeatedDigits[max])
			max = i;
	}

	cout << max;
	return 0;
}
