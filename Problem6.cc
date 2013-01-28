#include <iostream>

using namespace std;

int main(){
	const int bound = 100;
	long int SumOfSquare, SquareOfSum;

	SumOfSquare = (bound)*(bound+1)*(2*bound+1)/6; //Sum of Squares Equation
	SquareOfSum = (bound)*(1+bound)/2;             //Arithmetic Sum
	SquareOfSum *= SquareOfSum;                    //Sum is now squared

	cout << SquareOfSum - SumOfSquare;
	return 0;
}
