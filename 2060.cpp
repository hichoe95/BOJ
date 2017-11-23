#include <iostream>
using namespace std;

int p[101];

int FIND(int x){
  if(p[x] == x) return x;
  return p[x] = FIND(p[x]);
}

void UNI(int x, int y){
  x = FIND(x),y = FIND(y);
  p[y] = x;
}

int main(){
  ios_base::sync_with_stdio(0);

  int n,m;
  cin >> n >> m;

  for(int i=1 ; i <=n ; i++) p[i] = i;

  for(int i=0, x, y ; i<m ; i++){
    cin >> x >> y;
    UNI(x,y);
  }

  int ret = 0;
  for(int i=2 ; i<=n ; i++)
    if(FIND(1)==FIND(i)) ret++;

  cout << ret;
  return 0;

}
