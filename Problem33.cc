#include <iostream>

using namespace std;

//This question is not a programming question in my opinion.
//This question is a purely mathematical question and I will use C++ in this 
//solution only as a calculator.
//WARNING: This solution requires high algebraic ability

//We notice that we can set up the equation :
/*	(10a + b)/(10b + c) = a/c where a, b , c are between 1-9
	          10ac + bc = 10ab + ac
		   9ac + bc = 10ab
                        9ac = b(10a-c)

Case gcd(b,9) = 1
Then 9|(10a-c) or 9|(a-c) => a = c .. which implies a = c = b which is a trivial solution

Case gcd(b,9) = 9
Then b = 9. Therefore ac = 10a-c so 10 = c(a+1)/a. we can observe that either c or a+1 must
be 5 or 10. This produces solutions such as (a,c) = (4,8), (9, 9), (1, 5)

Case gcd(b, 9) = 3
Then b = 3 or 6. 

When b = 3, 3ac = 10a-c or 10 = c(3a+1)/a. We can observe that either c or 3a+1 must be 5, 10.
Note that 3a+1 cannot be 5 or 2 so we consider when 3a+1 is 10 (a = 3), and then c = 3.
Therefore (a,c) = (3,3) is a trivial solution

When b = 6, 3ac = 2(10a-c) or 10 = c(3a+2)/2a With similar analysis, we can find solutions to this.
3a+2 cannot be 10 or 2 but 3a+2 can be 5 (a=1). If a=1, then c = 4. When c = 2, (3a+2)/2a cannot be 5. 
When c = 5, (3a+2)/2a = 2 when a = 2. So (a,c) = (1,4), (2, 5)

IN ALL, there are 4 non-trivial solutions: (a,b,c) = (4, 9, 8), (1, 9, 5), (1, 6, 4), (2, 6, 5)
The fractions are : 49/98, 19/95, 16/64. 26/65
*/

//Simple Greatest Common Divisor algorithm
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
	//Divide denominator by GCD(num,denom) to reduce the fraction
	int GCD = gcd(49*19*16*26, 98*95*64*65);

	cout << 98*95*64*65/GCD;
	return 0;
}
