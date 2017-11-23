#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int n,s,m;
  cin >> n >> s >> m;
  vector<int> v(n+1);

  for(int i=1 ;i<=n ;i++) cin >> v[i];

  int d[101][1001]={0,};
  d[0][s] = 1;
  int ans = -1;

  for(int i=0 ;i<n ;i++){
    for(int j=0 ; j<=m ; j++){
      if(!d[i][j]) continue;
      if(j-v[i+1] >= 0) d[i+1][j-v[i+1]] = 1;
      if(j+v[i+1] <= m) d[i+1][j+v[i+1]] = 1;

    }
  }

  for(int i=0 ; i<=m ; i++) ans = (d[n][i] ? i : ans);

  cout << ans << '\n';
  return 0;
}
