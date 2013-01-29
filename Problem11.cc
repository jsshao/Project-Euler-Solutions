#include <iostream>
#include <fstream>

using namespace std;

int main(){
	int array[20][20], max = 0;

	ifstream in("Problem11.txt"); //saved question input into a text file to save time

	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 20 ; j++)
			in >> array[i][j];
	}
	in.close();
	
	//check adjacent elements
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++){
			int hori = 1, vert = 1, diagRight = 1, diagLeft = 1;
			for (int k = 0; k < 4; k++){
				if (j < 17)
					hori*=array[i][k+j]; //horizontal product
				
				if (i < 17)
					vert*=array[i+k][j]; //vertical product
				
				if (i < 17 && j < 17)
					diagRight*=array[i+k][j+k]; //diagonally right product

				if (i < 17 && j > 2)
					diagLeft*=array[i+k][j-k]; //diagonally left product	
				
				//Update new max
				if (hori > max) max = hori;
				if (vert > max) max = vert;
				if (diagRight > max) max = diagRight;
				if (diagLeft > max) max = diagLeft;
			}
		}
	
	cout << max;
	return 0;
}
