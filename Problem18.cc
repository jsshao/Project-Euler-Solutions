#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//credit goes to http://blog.singhanuvrat.com/problems/project-euler-maximum-sum-traversing-top-to-bottom-in-a-triangle
//with bottom-to-top sweep
//saved text file in Problem18.txt for simplicity's sake
int main(){
	ifstream in("Problem18.txt");
	vector <vector <int> > pyramid;
	
	for (int i = 0 ; i < 15; i++){
		vector <int> tempVector;
		for (int j = 0; j <= i; j++){
			int temp;
			in >> temp;
			tempVector.push_back(temp);	
		}
		pyramid.push_back(tempVector);
	}

	in.close(); //close file

	for (int i = 13; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			pyramid[i][j] += max(pyramid[i+1][j],pyramid[i+1][j+1]);			
	
	cout << pyramid[0][0];
	return 0;
}
