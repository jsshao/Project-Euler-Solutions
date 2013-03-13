#include <iostream>
#include <vector>

using namespace std;

//basic integer exponential function
int exponent(int a, int b){
	if (b==0) return 1;
	int ans = a;

	for (int i = 1; i < b; i++)
		ans*=a;

	return ans;
}

//find whether a value is in the vector
bool find (vector<int> a, int b){
	for (int i = 0; i < a.size(); i++)
		if (a[i]==b) return true;

	return false;
}

int main(){
	int total = 0; //total number of distinct powers
	bool explored[100] = {0}; //keeps track of which values of "a" has already been considered
	
	//iterate a
	for (int a = 2; a <= 100; a++){
		if (explored[a] == 0){          //only apply algorithm to values of "a" that are not already considered
			vector <int> powers;    //vector to hold all possible powers of "a" from a^2 - a^100
			int n = 1;
			
			while (exponent(a,n) <= 100){ //max value of a is 100
				explored[exponent(a,n)] = 1; //has been explored	
				
				//all possible values of b
				for (int i = 2; i <= 100; i++){
					if (find(powers,i*n) == 0){
						powers.push_back(i*n); //if the power has not been yet considered, push it
					}		
				}
				n++;
			}
			total += powers.size(); //the vector contains all distint powers of "a" 
		}
	}
	
	cout << total;
	return 0;
}
