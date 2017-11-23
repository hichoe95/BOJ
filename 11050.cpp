#include <iostream>
using namespace std;
const int MOD=10007;
int main(){
  int c[1001][1001]={0,};
  int n,k;
  cin >> n>>k;

  for(int i=1 ;i<=n ; i++){
    c[i][0]=c[i][i] = 1;
    for(int j = 1; j<=i-1 ;j++){
      c[i][j] = c[i-1][j-1] + c[i-1][j];
      c[i][j]%=MOD;
    }
  }
  cout << c[n][k] << '\n';

  return 0;

}
