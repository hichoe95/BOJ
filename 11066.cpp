#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int f[501];
int d[501][501];

int go(int x, int y){

  if(x==y) return 0;
  if(d[x][y]!=-1) return d[x][y];
  for(int i=x ;i<y ; i++){
    int tmp = go(x,i)+go(i+1,y)+f[y]-f[x-1];
    if(d[x][y] == -1 || tmp<d[x][y]) d[x][y] = tmp;
  }
  return d[x][y];
}

int main(){
  ios_base::sync_with_stdio(0);

  int t;
  cin >> t;

  while(t--){
    memset(f,0,sizeof(f));
    memset(d,-1,sizeof(d));

    int k;
    cin >> k;
    for(int i=1 ;i <=k ; i++){
      cin >> f[i];
      f[i] += f[i-1];
    }

    cout << go(1,k) <<'\n';

  }
  return 0;
}
