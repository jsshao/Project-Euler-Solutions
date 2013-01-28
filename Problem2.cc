#include <iostream>

using namespace std;

int main(){
	int previous = 1, current = 2;
	int sum = 0;

	while (current < 4000000){
		current = previous + current;
		previous = current - previous;

		if (previous%2==0)
			sum+=previous;			
	}
	
	cout << sum;
	return 0;
}
