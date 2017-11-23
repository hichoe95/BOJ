#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LIGHT -5
#define BLACK -1
#define WHITE -2
#define BULB 1

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int g[7][7];
int d[7][7];
int c[7];
int r[7];
int n;
cin >> n;

bool check(int x, int y){//설치하려는 전구 동서남북으로 다른전구가 있는지 확인
  if(x<n-1)
    for(int i=x+1 ;i<n;i++){
      if(g[i][y] == BLACK || g[i][y]>=0) break;
      if(d[i][y] == BULB) return false;
    }
  if(x>0)
    for(int i=x-1 ;i>=0 ; i--){
      if(g[i][y] == BLACK || g[i][y]>=0) break;
      if(d[i][y] == BULB) return false;
    }

  if(y>0)
    for(int i=y-1 ; i>=0 ; i--){
      if(g[x][i] == BLACK || g[x][i]>=0) break;
      if(d[x][i] == BULB) return false;
    }
  if(y<n-1)
    for(int i=y+1 ; i<n;i++){
      if(g[x][i] == BLACK || g[x][i]>=0) break;
      if(d[x][i] == BULB) return false;
    }
  return true;
}

void LIGHT1(int x, int y){//전구 켜진 동서남북으로 불켜기
  if(x<n-1)
    for(int i=x+1 ;i<n;i++){
      if(g[i][y] == BLACK || g[i][y]>=0) break;
      d[i][y] = LIGHT;
    }
  if(x>0)
    for(int i=x-1 ;i>=0 ; i--){
      if(g[i][y] == BLACK || g[i][y]>=0) break;
      d[i][y] = LIGHT;
    }

  if(y>0)
    for(int i=y-1 ; i>=0 ; i--){
      if(g[x][i] == BLACK || g[x][i]>=0) break;
      d[x][j] = LIGHT;
    }
  if(y<n-1)
    for(int i=y+1 ; i<n;i++){
      if(g[x][i] == BLACK || g[x][i]>=0) break;
      d[x][j] = LIGHT;
    }

}

void light(int x, int y){
  if(g[x][y] == BLACK || g[x][y] >=0) return;

  d[x][y] = BULB;
  LIGHT1(x,y);
  for(int i=x ;i<n;i++){
    for(int j=0 ; j<n;j++){
      if(g[i][j] >=0) continue;
      if(d[i][j]!=LIGHT && d[i][j] != BULB && g[i][j] != BLACK){
        light(i,j);
      }
    }
  }
  bool flag = true;
  for(int i=0 ;i<4;i++){
    int nx = x + dx[i], ny = y + dy[i];
    if(nx >=0 && nx<n && ny >= 0 && ny<n){
      if(g[nx][ny] ==0){
        flag = false;
        break;
      }
      if(g[nx][ny] >0) g[nx][ny]-=1;
    }
  }

  if(flag == false)

}


int main(){

  int t;
  cin >> t;

  while(t--){
    cin >> n;
    for(int i=0 ;i<n; i++)
      for(int j=0 ;j<n; j++)
        cin >> g[i][j];


  }

  return 0;
}
