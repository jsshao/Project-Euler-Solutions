#include <iostream>

using namespace std;

int main(){
	//Basic Sieve of Eratosthenes
	bool array[2000000] = {0};
	unsigned long int sum = 0;

	for (int i = 2; i < 2000000; i++){
		if (!array[i]) {
			int counter = 2*i;
			while (counter < 2000000){
				array[counter] = 1;
				counter += i;
			}
		}
	}

	for (int i = 2; i < 2000000; i++)
		if (!array[i])
			sum += i;

	cout << sum;	
	return 0;
}
