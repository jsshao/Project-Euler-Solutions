#include <iostream>
#include <vector>

using namespace std;

//Reverse the integer digit by digit then compare to original number
bool isPalindrome(int n){
	int reverse = 0, temp = n;
	
	//reveerse the number in "temp"
	while (temp){
		reverse *= 10;
		reverse += temp%10;
		temp = temp/10;
	}

	if (n == reverse) return 1;
	return 0;
}

//Convert to binary then check first digit with last..etc
bool isBinPalin(int n){
	vector <int> binary;
	if (n == 0) return true;

	//use modulus to find binary representation
	while (n){
		binary.push_back(n%2);
		n /= 2;
		
	}
	for (int i = 0; i < binary.size()/2; i++){
		if (binary[i] != binary[binary.size() - 1 -i])
			return false;
	}
	return true;
}

int main(){
	int sum = 0;
	
	//Sum up all palidromes under 10^6
	for (int i = 0; i < 1000000; i++){
		if (isPalindrome(i) && isBinPalin(i)) sum+=i;	
	}
	
	cout << sum;
	return 0;
}
