#include <iostream>

using namespace std;

//Sunday - 0, Monday - 1.... Saturday - 6

bool isLeap(int num){
	if (num % 400 == 0) return true;
	if (num % 100 == 0) return false;
	if (num % 4 == 0 ) return true;
	return false;
}

int main(){
	int DaysOfMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int StartingDay = (1+365)%7; //Day of the week on Jan 01, 1901
	int CurrentDay = StartingDay;
	int counter = 0;	

	for (int i = 1901; i <= 2000; i ++){     //every year
		for (int j = 0; j < 12; j++){   //every month
			if (CurrentDay == 0) counter ++; //begins on sunday!
			
			CurrentDay += DaysOfMonths[j];
			if (isLeap(i) && j==1) CurrentDay ++ ; //leap year day
			CurrentDay %= 7;
		}
	}

	cout << counter;
	return 0;
}
