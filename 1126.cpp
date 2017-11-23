#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1000000009;

int n;
int t[51];
int d[51][250001]={0,};

int go(int x, int dif){

  if(dif > 250000) return -INF;

  if(x==n) return (dif ? -INF : 0);

  int &ans = d[x][dif];
  if(ans!=-1) return ans;
  ans = go(x+1,dif);
  ans = max(ans,go(x+1,dif + t[x]));
  ans = (t[x]>dif ? max(ans,dif + go(x+1,t[x]-dif)) : max(ans,t[x] + go(x+1,dif-t[x])) );

  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  memset(d,-1,sizeof(d));

  cin >> n;

  for(int i=0 ;i<n;i++) cin >> t[i];

  int ans = go(0,0);

  cout << (ans ? ans : -1) << '\n';

  return 0;
}
