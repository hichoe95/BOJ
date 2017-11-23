#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[1002];
int d[1002][1002];
int t,w;

int go(int s, int m){
  if(s>t || m>w) return 0;
  if(d[s][m]!=-1) return d[s][m];
  return (d[s][m] = max(go(s+1,m+1),go(s+1,m))+(m%2+1 == a[s] ? 1 : 0));
}

int main(){
  ios_base::sync_with_stdio(0);
  cin >> t >> w;
  memset(d,-1,sizeof(d));
  for(int i=0 ;i<t ; i++) cin >> a[i];

  cout << max(go(0,0),go(0,1)) << '\n';
  return 0;
}
