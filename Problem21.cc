#include <iostream>
#include <cmath>

using namespace std;

//returns the d(n) function
int SumOfDivisors (int n){
	int sum = 0;
	for (int i = 1; i < (n); i++){
		if (n%i==0) sum+=i;
	}
	return sum;
}

int main(){
	int sum = 0;
	for (int i = 2; i <= 10000; i++){
		int a = SumOfDivisors(i);
		int b = SumOfDivisors(a);
		if (b==i && i!=a)         //if d(i) == d(d(i) then they are amicable numbers
			sum+=i;
	}	
	cout << sum;
	return 0;
}
