#include <iostream>
#include <vector>

using namespace std;

//Note that at most, we need to consider 6 digit numbers.
//This is because as soon as we consider 7 digit numbers, we realize this is impossible
//since 9999999 (greatest 7-digit) has a sum of fifth powers of 413343 which is only six digits

int exponent (int a, int b){
	if (b ==0 ) return 1;
	int ans = a;

	for (int i = 1; i < b; i++)
		ans*=a;

	return ans;
}

int main(){
	int sum = 0;
	vector <int> powersOfFive;	
	
	//1 digit
	for (int i = 0; i < 10; i++)
		powersOfFive.push_back(exponent(i,5));

	//2 digits
	for (int i = 1; i < 10; i++){
		for (int j = 0; j <10; j++){
			powersOfFive.push_back(powersOfFive[j]+exponent(i,5));
		}
	}

	//3 digits
	for (int i = 1; i < 10; i++){
		for (int j = 0; j < 100; j++)
			powersOfFive.push_back(powersOfFive[j] + exponent(i,5));
	}
	
	//4 digits
	for (int i = 1; i < 10; i++){
		for (int j = 0; j< 1000; j++)
			powersOfFive.push_back(powersOfFive[j]+exponent(i,5));
	}

	//5 digits
	for (int i = 1; i < 10; i++){
		for (int j = 0; j< 10000; j++)
			powersOfFive.push_back(powersOfFive[j] + exponent(i,5));
	}

	//6 digits
	for (int i = 1; i < 10; i++){
		for (int j = 0; j< 100000; j++)
			powersOfFive.push_back(powersOfFive[j] + exponent(i, 5));
	}

	//check if number == sum of fifth powers
	for (int i = 10; i< powersOfFive.size(); i++){
		if (i == powersOfFive[i])
			sum += i;
	}

	cout << sum; 
	return 0;
}
