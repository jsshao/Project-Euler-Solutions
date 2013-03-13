#include <iostream>

using namespace std;

//Recursive Solution!!! : I check all possibilities starting at the 2 pounds 
//Then progressively move my way down to the 1 pence
//Everytime I recurse down to the 1 pence, that traversal is a distinct combination
//Therefore I just keep a counter of how many times I traverse down to the 1 pence

void possibilities(int remaining, int coin, int &n){
	int nextCoin; //the progressions from 2 pounds to 1 pence
	
	if (coin == 200) nextCoin = 100;
	else if (coin == 100) nextCoin = 50;
	else if (coin == 50) nextCoin = 20;
	else if (coin == 20) nextCoin = 10;
	else if (coin == 10) nextCoin = 5;
	else if (coin == 5) nextCoin = 2;
	else if (coin == 2) nextCoin = 1;
	
	//Successfully traversed down to 1 pence
	else if (coin == 1){
		n++;
		return ;
	}

	//Recursive step to test the appropriate next coin
	for (int i = 0; i <= remaining/coin; i++){
		possibilities(remaining - coin*i, nextCoin, n);
	}
}

int main(){
	int n = 0; //number of ways
	
	//recursive call
	possibilities(200, 200, n);

	cout << n;
	return 0;
}
