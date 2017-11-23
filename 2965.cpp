#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;

  int M = max(b-a,c-b);

  cout << M-1 << endl;

  return 0;
}
