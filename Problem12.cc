#include <iostream>
#include <cmath>

using namespace std;

int main(){
	//note triangular numbers can be written in form n*(n+1)/2
	
	int n = 1, divisors = 1;
	
	while (divisors <= 500){
		int a = n, b = n+1; // a*b/2 = triangular number
		int aDivisors = 0, bDivisors = 0;
		
		if (a%2==0) a/=2; //divide either a or b by 2 to get the actual factor
		if (b%2==0) b/=2;		

		for (int i = 1; i <= (a); i++)
			if (a%i==0) aDivisors++;      //number of divisors for a
		
		for (int i = 1; i <= (b); i++)
			if (b%i==0) bDivisors++;      //number of divisors for b		 
		
		divisors = aDivisors * bDivisors;     //since triangular number = a*b, its factors are also number of factors for a * number of factors for b
		n++; //increment for next triangular number
	}

	cout << n*(n-1)/2;
	return 0;
}
