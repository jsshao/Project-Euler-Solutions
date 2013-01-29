#include <iostream>

using namespace std;

int main(){
	bool passed[1000000] = {0}; //optimization: keep track of which numbers have already been passed through during a previous sequence
	int maxIters = 0, maxStarting = 1;

	for (int i =2; i < 1000000; i++){
		if(passed[i] == 0){
			passed[i] = 1;
			long int num = i;
			int counter = 0;		
	
			while (num != 1){
				counter++;
				if (num%2) num = 3*num+1;
				else num/=2;
				
				if (num < 1000000)
					passed[num] = 1;
			}
			if (counter > maxIters){
				maxIters = counter;
				maxStarting = i;	
			}
		}
	}

	cout << maxStarting;
	return 0;
}
