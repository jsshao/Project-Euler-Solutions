#include <iostream>
#include <vector>

using namespace std;

//factorial function
int fact(int n){
    if (n==0) {
             return 1;
    }
    int answer = 1;
    for (int i = n; i > 1; i--)
        answer*=i;
      
    return answer;
}


int main(){
    //Keeps track of all sum of factorials
    vector <int> SumOfFact;
    int facts[10] = {0};
    
	//Uses a local array to keep track of the factorials for efficiency
    for (int i = 0; i < 10; i++)
        facts[i] = fact(i);
        
    //Set up the numbers from 0-9 as a starting point
    for (int i = 0; i < 10; i++)
        SumOfFact.push_back(fact(i));

	//Calculate the SumOfFact up to 9999999 because we notice 8 digits is the limit
	//The upper bound is 7 digits because even the largest 8 digit number (99 999 999) has a sum of factorials < 8 digits    
    for (int k = 0; k < 6; k++){      //Run this algorith 6 times which provides 7 digits max
        int total = SumOfFact.size();
        for (int i = 1; i < 10; i++){ //Concatenate 1-9 on top of all the previous numbers
            for (int j = 0 ; j < total; j++){
                SumOfFact.push_back(facts[i]+SumOfFact[j]);
            }
        }
    }    
    
	//Fix all non-trailing zeroes by adding 0! for every hidden 0
    for (int i = 0; i < SumOfFact.size(); i++){
        int n = SumOfFact[i];
        n/=10; //ignore trailing zero
        while (n>0){
              if (n%10==0) SumOfFact[i]++; //If 0 is found, add 0! to its value
              n/=10;
        }    
    }
    
    int sum = 0;
    for (int i = 10; i < SumOfFact.size(); i++){
        if (SumOfFact[i] == i) sum += i; //Calculate which numbers are digit factorials
    }
    
    cout << sum;
    return 0;
}
