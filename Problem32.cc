#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Note this question isn't hard at all. However, you must optimize it extremely careful
//For example, we note that both the multiplier and multiplicand MUST be < 10^5 or else it's impossible
//to have the other numbers add up to 9 digits

//Also, when choosing the multiplier, the max,min bounds of the multiplicand can be calculated by:
//Let x = digits of multiplier, let y = digits of multiplicand, and x+y bounds digits of product
//x + y + x + y = 9
//2x + 2y = 9
//Therefore, we can bound y by (9-2x)/2 but we want ceil((9-2x)/2)
//So instead, I use the formula (10-2x)/2


//returns # digits of the number n
int digits(int n){
	int counter = 0;
	while (n!=0){
		counter++;
		n/=10;
	}
	return counter;
}

//exponent function
int exponent(int n, int e){
	int ans = n;

	for (int i = 1; i < e; i++){
		ans*=n;
	}
	return ans;
}

//returns whether b is in the vector a
bool vectorFind(vector<int> a, int b){
	for (int i = 0; i < a.size(); i++){
		if (a[i] == b)
			return true;
	}
	return false;
}

//is the number pandigital
bool pandigital(int n){
	if (n > 987654321) return false;

	int check[10]={0};

	while (n!=0){
		check[n%10] = 1;
		n/=10;
	}

	for (int i = 1; i <= 9; i++)
		if (check[i]==0)
			return false;

	return true;
}

int main(){
	int sum = 0;
	vector<int> a; //vector of all the pandigital products
	
	//multiplier
	for (int i = 1; i < 10000; i++){
		//optimization of the multiplicand
		for (int j = exponent(10, (10-2*(digits(i)+1))/2); j < exponent(10,(10-2*digits(i))/2); j++){ 
			//prevent overflow of integer	
			if (digits(i) + digits(j) + digits(i*j) > 9) continue;
			
			//concatenate the 3 numbers together
			int combined = i + j*exponent(10,digits(i)) + i*j*exponent(10, digits(i)+digits(j));
			
			//avoid duplicate pandigital products
			if (pandigital(combined) && vectorFind(a, i*j)==0)
				a.push_back(i*j);
			
		}
	}

	//sum calculation
	for (int i = 0; i < a.size(); i++){
		sum+=a[i];
	}
	
	cout << sum;
	return 0;
}
