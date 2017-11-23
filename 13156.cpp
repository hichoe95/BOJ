#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int c,m;
  int a[101][101];
  int dp[101][101]={0,};
  cin >> c >> m;

  for(int i=1 ; i<=m ; i++)
    for(int j=1 ; j<=c ; j++)
      cin >> a[i][j];
  int M=-1;
  for(int i=1 ;i <= m ;i++){
    for(int j = 0 ; j<=c ; j++){
      for(int k = 0 ; j-k>=0; k++){
        dp[i][j] = max(dp[i][j],dp[i-1][k] + a[i][j-k]);
        M = (dp[i][j]>M ? dp[i][j] : M);
      }
    }
  }
  cout << M << '\n';
  return 0;
}
