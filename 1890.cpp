#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int g[101][101];
long long dp[101][101];

long long go(int i, int j){

  if(i==0 && j==0) return 1;
  if(dp[i][j]) return dp[i][j];

  for(int k = 0 ; k <i ; k++)
    if(g[k][j]+k == i) dp[i][j] += go(k,j);

  for(int k = 0 ; k< j ; k++)
    if(g[i][k]+k == j ) dp[i][j] += go(i,k);

  return dp[i][j];
}

int main(){
  ios_base::sync_with_stdio(0);

  cin >> n;

  for(int i=0 ;i<n; i++)
    for(int j=0 ;j<n ; j++)
      cin >> g[i][j];

  dp[n-1][n-1] = 0;
  cout << go(n-1,n-1) << '\n';

  return 0;
}
