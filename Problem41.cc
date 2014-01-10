#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

/*
We are trying to find the largest pandigital prime so we begin with testing 9-digit pandigital primes,
then 8-digit, then 7-digit, etc

The sum of digits of a n-th pandigital number is fixed as the digits include 1 - n. We also know
that if the sum of digits of a number is divisible by 3, then the number is also divisible by 3

Using this divide by 3 heuristic, we can ignore certain values of n for the digit length

9 digits
--------
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45 and 3 | 45
Therefore, 3 divides all 9-digit pandigitals which means they CANNOT be prime

8 digits
--------
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 = 36 and 3 | 36

7 digits
--------
1 + 2 + 3 + 4 + 5 + 6 + 7 = 28 and 3 does NOT divide 36

6 digits
--------
1 + 2 + 3 + 4 + 5 + 6 = 21 and 3 | 21

5 digits
--------
1 + 2 + 3 + 4 + 5 = 15 and 3 | 15

4 digits
--------
1 + 2 + 3 + 4 = 10 and 3 does NOT divide 10

3 digits
--------
1 + 2 + 3 = 6 and 3 | 6

2 digits
--------
1 + 2 = 3 and 3 | 3

*/

void generatePandigital(int num, vector<int> remaining);
bool isPrime(int num);


int main()
{
	/* Generate 7 digit pandigital numbers and test if they are prime */	
	vector<int> digits;
	for (int i = 1; i <= 7; i++) {
		digits.push_back(i);
	}	

	generatePandigital(0, digits);
	return 0;
}

/* Recursively generates all possible permutations of 7 digit pandigital numbers
 * Generate it backwards so that it finds the largest numbers. Once a 7-digit
 * pandigital is generated, test for primeness 
 */
void generatePandigital(int num, vector<int> remaining)
{
	if (remaining.empty() && isPrime(num) ) {
		cout << num << endl;
		exit(0);
	}

	for (int i = remaining.size()-1; i >= 0; i--) {
		int temp = 10 * num + remaining[i];
		vector<int> newRemaining = remaining;
		newRemaining.erase(newRemaining.begin() + i);
		generatePandigital(temp, newRemaining);
	}
}

/* Checks if number is prime */
bool isPrime(int num) 
{
	for (int i = 2; i <= sqrt(num); i++) {
		if (0 == num % i) {
			return false;
		}
	}

	return true;
} 
