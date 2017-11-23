#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000000

long long int d[201][201];

int main(){
  ios_base::sync_with_stdio(false);
  int n,k;
  cin >> n >> k;

  d[0][0] = 1;
  for(int i=0 ;i<=n;i++){
    for(int j= 1; j<=k;j++){
      for(int q=0;q<=i;q++)
        d[i][j] += d[i-q][j-1];
        d[i][j]%=MOD;
    }
  }

  cout << d[n][k]%MOD << endl;
  return 0;
}
