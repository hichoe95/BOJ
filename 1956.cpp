#include <iostream>
using namespace std;

#define INF 1e9

int d[401][401];
int main(){
  ios_base::sync_with_stdio(0);
  int n,m;
  cin >> n >> m;
  for(int i=1 ; i<=n;i++)
    for(int j=1 ; j<=n;j++)
      d[i][j] = INF;

  for(int i=0 ;i<m ;i++){
    int u,v,w;
    cin >> u >> v >> w;
    d[u][v] = w;
  }

  for(int k = 1; k<=n ; k++)
    for(int i=1;i<=n;i++)
      for(int j=1 ; j<=n;j++)
        d[i][j] = min(d[i][j],d[i][k] + d[k][j]);

  int ans = INF;
  for(int i=1 ; i<=n ;i++) ans = min(ans,d[i][i]);

  cout << (ans==INF ? -1 : ans) << '\n';
  return 0;
}
