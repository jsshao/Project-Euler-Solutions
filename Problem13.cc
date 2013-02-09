#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	ifstream in("Problem13.txt"); //open up file for simplicity
	char matrix[100][50];  //use a matrix to store one-hundred 50 digit numbers
	vector <int> sum;
	
	//read in numbers from text file
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 50; j++){
			in >> matrix[i][j];		
			matrix[i][j] -= 48;
		}
	}

	//sum up the numbers and put the digits into the vector "sum"
	for(int i = 49; i >= 0; i--){
		for (int j = 0; j < 100; j++){
			if (49-i < sum.size())
				sum[49-i] += matrix[j][i]; //carry over
			else
				sum.push_back(matrix[j][i]); //carry over to a new digit
		}
		
		//checks and ensures that each digit is less than 10
		for (int j = 49-i; j < sum.size(); j++){
			if (sum[j]/10 > 0){
				if (j != sum.size()-1)
					sum[j+1] += sum[j]/10;
				else
					sum.push_back(sum[j]/10);
			}
			sum[j] %= 10;
		}
	}
	
	//find first 10 digits
	for (int i = sum.size()-1; i>= sum.size() - 10; i--){
		cout << sum[i];
	}

	return 0;
}
