#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9

int d[20][20];
bool x[20][20];

int main(){
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;

  for(int i=0 ;i<n;i++)
    for(int j=0 ;j<n ; j++)
      cin >> d[i][j];

  for(int k=0 ;k<n;k++)
    for(int i=0 ;i<n; i++){
      if(i==k)continue;
      for(int j=0 ;j<n ;j++){
        if(i==j || j==k) continue;
        if(d[i][j] > d[i][k] + d[k][j]){
          cout << -1 << '\n';
          return 0;
        }
        if(d[i][j] == d[i][k] + d[k][j]) x[i][j] = true;
      }
    }

  int ans =0;
  for(int i=0 ;i<n;i++)
    for(int j=0 ;j<n;j++)
      if(!x[i][j]) ans+=d[i][j];

  cout << ans/2 << '\n';


  return 0;
}
