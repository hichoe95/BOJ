#include <iostream>
#include <vector>
using namespace std;

#define INF 1e9

int d[100][100];
int v[100][100];

int main(){
  ios_base::sync_with_stdio(0);

  int n,m;
  cin >> n >> m;

  for(int i=0 ;i<n;i++)
    for(int j=0 ;j<n;j++)
      d[i][j] = (i==j ? 0 : INF);

  for(int i=0 ;i<m;i++){
    int a,b,c;
    cin >> a >> b >> c;
    if(d[a-1][b-1] > c) d[a-1][b-1] = c,v[a-1][b-1] = b-1;
  }

  for(int k=0 ;k<n;k++)
    for(int i=0 ;i<n;i++)
      for(int j=0 ;j<n;j++)
        if(d[i][j] > d[i][k] + d[k][j]){
          d[i][j] = d[i][k] + d[k][j];
          v[i][j] = v[i][k];
        }

  for(int i=0 ;i<n;i++){
    for(int j=0 ;j<n;j++)
      if(i==j || d[i][j] == INF) cout << 0 << " ";
      else cout << d[i][j] << " ";
    cout << '\n';
  }

  for(int i=0 ;i<n;i++){
    for(int j=0; j<n ;j++){
      if(i==j || d[i][j] == INF){
        cout << 0 << '\n';
        continue;
      }
      vector<int> p(1,i);
      for(int k=i;k!=j;){
        p.push_back(k=v[k][j]);
      }
      cout << p.size();
      for(int k : p) cout << " " << k+1;
      cout << '\n';
    }
  }

  return 0;
}
