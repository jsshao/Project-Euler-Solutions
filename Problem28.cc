#include <iostream>

using namespace std;

int main(){
	//using mathematical analysis, i can develop a sequence for each diagonal
	//note that the sequences are all quadratic as their second differences are constant
	
	//1, 3, 13... = 4x^2 - 2x + 1 where x starts from 0
	//1, 9, 25... = 4x^2 + 4x + 1 
	//1, 7, 21... = 4x^2 + 2x + 1
	//1, 5, 17... = 4x^2 + 1
	
	unsigned int sum = 0;
	
	//we notice that 1001 by 1001 grid has 1001 elements in the diagonal
	//so we iterate for (1001-1)/2=500 elements for each half of the diagonal

	for (int i = 0; i <= 500; i++){
		sum+= 4*i*i-2*i+1;
		sum+= 4*i*i+4*i+1;
		sum+= 4*i*i+2*i+1;
		sum+= 4*i*i+1;
	}
	sum-=3; //subtract 3 because we added the centre 1 four times rather than just once

	cout << sum;
	return 0;
}
