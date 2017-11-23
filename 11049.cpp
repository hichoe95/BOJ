#include <iostream>
#include <cstring>
using namespace std;

int m[505];
int dp[505][505];

int go(int x, int y){
  if(x==y) return 0;
  if(dp[x][y]!=-1) return dp[x][y];

  int &ret = dp[x][y];

  for(int i=x ;i<y; i++){
    int tmp = go(x,i) + go(i+1,y) + m[x] * m[i+1] * m[y+1];
    if(ret==-1 || tmp < ret) ret = tmp;
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  memset(dp,-1,sizeof(dp));
  int n;
  cin >> n;
  for(int i=0 ;i<n;i++) cin >> m[i] >> m[i+1];

  cout << go(0,n-1) << '\n';

  return 0;
}
