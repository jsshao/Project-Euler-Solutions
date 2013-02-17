#include <iostream>
#include <string>
#include <vector>

using namespace std;

//basic "next permutation" recursive function
//It's run-time complexity is O(n*n!) I believe
void permutate (vector <string> &a, string original, string perm){
  if (original == "")
    a.push_back(perm);
  else{
    for (int i = 0; i < original.length(); i++){
      string ori2 = original, perm2 = perm;
      ori2.erase(i,1);
      perm2+=original[i];
      permutate (a, ori2, perm2);
    }
  }
}

int main(int argc, char *argv[]){
  vector <string> a;                 //append all permutations in a vector
  
  permutate(a,"0123456789", "");

  cout << a[999999];                 //retrieve the 1000000th premutation
  return 0;
}




