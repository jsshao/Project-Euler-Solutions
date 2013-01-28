#include <iostream>

using namespace std;

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
	unsigned long int num = 2520; //given as evenly divisible from 1-10
	
	for(int i = 11; i <= 20; i++){
		if (num%i)                     //i is not a factor of num
			num *= i/(gcd(num,i)); //multiply num by what's necessary to make i a factor
	}
		
	cout << num;
	return 0;
}
