#include <iostream>

using namespace std;

/*Note that n>1 therefore the number being multiplied can be AT MOST 5 digits
or else its product with (1,2) will exceed the 9 digit threshhold. Also note
that Project Euler provides you with a pandigital product that begins with 9
Therefore, the first digit of the number must be a 9. Then, it can be at
MOST 4 digits due to the work of carry-overs

Case: 1 Digit - 9: 9*(1,2,3,4,5) = 918273640 is not pandigital

Case: 2 Digits - 9X is impossible because 9X*(1,2,3) is 8 digits
		 			  9X*(1,2,3,4) is 11 digits

Case: 3 Digits - 9XX is impossible because 9XX*(1,2) is 7 digits
					   9XX*(1,2,3) is 11 digits

IT HAS TO BE 4 DIGITS: 9XXX but the second most significant digit must be
smaller than 5 because if it wasn't 9XXX*(2) = 19XX because of the carry-over.

The range for numbers are now from 9000 - 9499 but since it cannot have any
redundant digits, the range is actually from 9123-9487.

More optimization is possible (such as last digit can't be 4) but I will 
let the program take over for now

*/
bool isPandigital(int a){
	bool verify[10] = {0};
	while (a){
		verify[a%10] = 1;
		a /= 10;
	}

	for (int i = 1; i < 10; i++)
		if (verify[i]==0)
			return false;

	return true;
}
int main(){
	
	for (int i = 9487; i >= 9123; i--){
		if (isPandigital(i*100000+i*2)){
			cout << i*100000+i*2;
			return 0;
		}
	}
}
