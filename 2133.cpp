#include <iostream>
using namespace std;
long long int d[31];
int main(){
  int n;
  cin >> n;
  d[0] = 1, d[2] = 3;
  for(int i=4;i<=n;i+=2){
    d[i] = d[i-2]*3;
    for(int j=4; j<=i;j+=2)
      d[i]+=d[i-j]*2;
  }
  cout << d[n] << endl;
  return 0;
}
