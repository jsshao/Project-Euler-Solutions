#include <iostream>

using namespace std;

//calculates the sum of its proper divisors
int sumOfDivisors (int n){
  int sum = 0;
  for (int i = 1; i <= n/2; i++)
    if (n%i==0)
      sum += i;
  return sum;
}


int main(){
  bool abundant[28123] = {0};         //whether the number is abundant or not
  bool SumOfAbundant[28123] = {0};    //whether the number can be written as sum of 2 abundant #

  //find all abundant numbers under 28123
  for (int i = 1; i <= 28123; i++){
    if (sumOfDivisors(i) > i)
      abundant[i] = 1;
  }

  //find all numbers that are sums of other abundant numbers
  for (int i = 1; i <= 28123; i++)
    for (int j = i; j <= 28123; j++){
      if (abundant[i] && abundant[j] && (i+j) <= 28123)
        SumOfAbundant[i+j] = 1;
    }

  //arithmetic sum of numbers from 1 to 28123
  unsigned long int sum = (28123+1)*28123/2;

  //subtract away all the numbers that can be written as two abundant numbers
  for (int i = 1; i <= 28123; i++)
    if (SumOfAbundant[i])
      sum-=i;

  //now this is the sum of all numbers that CANNOT be written as a sum of two abundant numbers
  cout << sum;
  return 0;

}
