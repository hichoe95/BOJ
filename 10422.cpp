#include <iostream>
using namespace std;

long long d[2501];
long long MOD = 1000000007ll;

int main(){

  d[0] = 1;
  for(int i=0 ;i<=2500 ; i++)
    for(int j=0 ;j<i ;j++){
      d[i] += d[j] * d[i-1-j];
      d[i]%=MOD;
    }

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << (n%2 ? 0 : d[n/2]) << '\n';
  }

  return 0;
}
