#include <iostream>
#include <cmath>

using namespace std;

/* This solution is based of high level mathematical analysis. If you do not understand Euclid's Formula
for Pythagorean Triples, please read up on it. The formula states that a pythagoream triple is formed STRICTLY of:
a = m^2 - n^2, b = 2mn, c = m^2 + n^2 and such that a^2 + b^2 = c^2 under the
condition that m > n, m and n are coprime, and that m-n must be odd.

However, these are the basic pythagorean triples, ALL pythagrean triples
can be represented as a = K(m^2 - n^2), b = K(2mn), c = K(m^2 + n^2) where K
is an arbitrary integer. Therefore, in this question, I'm under the constraint
that a + b + c = p or 2Km^2 + 2kmn = p or 2KM(m+n) = p. Note that p is even.

I use my program to test for all even p's between 2-1000 and find the set of
all (m,n) solutions which is injective to the set of all (a,b,c) solutions.
*/

//Basic Euclidean Algorithm for GCD
int gcd(int a, int b){
	int r = a%b;
	while (r){
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}

int main(){
	//Greatest perimeter and greatest number of solutions
	int max = 0, maxP = 0;
	
	//Only look at even numbers
	for (int i = 2; i <= 1000; i+=2){
		int curr = 0; //temp
		for (int j= 1; j<=sqrt(i); j++){
			for (int k = 1; k < j; k++){ // k < j
				//j,k are coprime, j-k is odd, and 2j(j+k) divides i because of the K constant discussed above
				if (gcd(j,k)==1 && (j-k)%2 == 1 && gcd(2*j*(j+k), i) == 2*j*(j+k))
					curr ++ ;
			}
		}
		//Reset max if the new number has more solutions
		if (curr > max){
			maxP = i;
			max = curr;
		}
	}

	cout << maxP;
	return 0;
}
