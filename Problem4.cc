#include <iostream>
#include <string>

using namespace std;

int main(){
	int max = 0;
	
	for (int i = 999; i >= 100; i--){
		for (int j = i; j >= 100; j--){
			int product = i*j;
			int reverse = 0;
			
			while(product > 0){
				reverse = reverse*10 + product%10;
				product/=10;
			}

			if (reverse == i*j) 
				if (i*j > max)
					max = i*j;
		}
	}
	
	cout << max;
	return 0;
}
