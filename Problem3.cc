#include <iostream>
#include <cmath>

using namespace std;

int main(){
	unsigned long int num = 600851475143;
	
	for (int i = 3; i < sqrt(num); i++){ //since num is not even, I start at 3 
		if (num%i==0){
			num/=i;
			i--;
		}
	}
	
	cout << num;
	return 0;
}
