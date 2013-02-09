#include <iostream>
#include <vector>

using namespace std;

int main(){
	//vector to hold all digits of 100! 
	vector<int> a(1, 2);
	
	for (int i = 3;i < 101; i++){ //perform multiplication 1000 times
		//carry over and constant size of digits after every mutiplication
		int carry = 0;
		int size = a.size();
		
		for (int j = 0; j < size; j++){
			a[j]*=i;                  //multiply
			a[j]+=carry;              //add the carry from last step
			carry = 0;
			if (a[j]/10 > 0) {
				if (j == a.size()-1)
					a.push_back(a[j]/10); //new digit is carried over
				else 
					carry= a[j]/10;       //store carry for next digit
				a[j] %= 10;                   //mod 10 to limit the digit
			}
		}
		
		//After multiplication, take care off the extra digits		
		if (size != a.size()){
			for (int j = size; j < a.size(); j++){
				if (j == a.size()-1 && a[j]/10 > 0)
					a.push_back(a[j]/10);
				else
					a[j+1] += a[j]/10;
				a[j]%=10;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < a.size(); i++)
		sum+=a[i]; //calculate sum

	cout << sum;
	return 0;
}
