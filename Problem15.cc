#include <iostream>

using namespace std;

int main(){
	//Read up on lattice paths and Pascal's Triang
	//A simple combination formula can be used
	//In this case: 40C20 = 40!/(20!*20!)

	unsigned long int ans = 1;
	
	for (int i = 40; i >= 21; i--){ 
		if (i%2==0) ans*= 2;     //to prevent overflow
		else ans*=i;
	}

	for (int i = 2; i <= 10; i++)
		ans/=i;


	cout << ans;
	return 0;
}
