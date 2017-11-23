#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  long long int n;
  cin >> n;
  cout << n << " ";
  while(n!=1){
    if(!(n%2)) n/=2;
    else n = n*3+1;
    cout << n << " ";
    if(n==1){
      cout << '\n';
      return 0;
    }
  }
  cout << '\n';
  return 0;
}
