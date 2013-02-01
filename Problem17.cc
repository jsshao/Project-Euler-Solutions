#include <iostream>

using namespace std;

//this is not a program: this is a calculator
int main(){
	int sum = 0;
	
	//units digit: _ 1, _ 2, _ 3...
	sum += 3*10;
	sum += 3*10;
	sum += 5*10;
	sum += 4*10;
	sum += 4*10;
	sum += 3*10;
	sum += 5*10;
	sum += 5*10;
	sum += 4*10;

	//adjust for special cases
	sum += 3; //ten
	sum += 3; //eleven
	sum += 3; //twelve
	sum += 3; //thirteen
	sum += 4; //fourteen
	sum += 3; //fifteen
	sum += 4; //sixteen
	sum += 4; //seventeen
	sum += 3; //eighteen
	sum += 4; //nineteen
	
	//10's digit: 2_, 3_, 4_ ...
	sum += 6*10; //twenty
	sum += 6*10; //thirty
	sum += 5*10; //forty
	sum += 5*10; //fifty
	sum += 5*10; //sixty
	sum += 7*10; //seventy
	sum += 6*10; //eighty
	sum += 6*10; //ninety 

	//previous tens and units digit repeat for every hundred
	sum*= 10; //000, 100, 200, 300 ... 900
	
	sum+=7*100*9; //HUNDRED: 7 letters, used from 0 - 99 (100), used from 100 - 900 (9)
        
	//1_ _, 2 _ _, 3_ _...
	sum += 3*100; //one before the hundred appears 100 times
        sum += 3*100; //two ""
        sum += 5*100;
        sum += 4*100;
        sum += 4*100;
        sum += 3*100;
        sum += 5*100;
        sum += 5*100;
        sum += 4*100;

	sum+= 3 * 99 * 9; //AND
	sum += (3+8); //1000
	
	cout << sum;
	return 0;
}
