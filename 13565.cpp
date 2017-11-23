#include <cstdio>

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int m,n;
int g[1010][1010];
bool visited[1010][1010];

bool go(int x,int y){
  bool flag = false;

  if(x == m) return true;

  visited[x][y] = true;

  for(int i=0 ;i<4 ; i++){
    int nx = x + dx[i], ny = y + dy[i];
    if(g[nx][ny] && !visited[nx][ny]){
      flag = go(nx,ny);
    }
    if(flag) break;
  }
  return flag;
}

int main(){

  scanf("%d %d",&m,&n);

  for(int i=1 ;i<=m; i++)
    for(int j=1 ; j<=n ; j++){
        int x;scanf("%1d",&x);
        g[i][j] = (x?0:1);
    }

  for(int i=1 ; i<=n ; i++){
    if(g[1][i] && !visited[1][i]){
      if(go(1,i)){
          puts("YES");
          return 0;
      }
    }
  }

  puts("NO");
  return 0;
}
