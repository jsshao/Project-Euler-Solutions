#include <iostream>

using namespace std;

int main(){
	//2 euqations but 3 variables: Diophantine Equation
	int c;
	
	for (int b = 0; b < 1000; b++){
		for (int a = 0; a < b; a++){
			c = 1000 - a - b;
			if (a*a+b*b == c*c) 
				cout << a*b*c;	
		}
	}

	return 0;
}
