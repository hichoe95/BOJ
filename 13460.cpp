#include <iostream>
#include <vector>
using namespace std;
#define x first
#define y second
#define INF 1e9

#define WALL 100

int g[10][10];
pair<int,int> r,b,h;
int n,m;
bool rdrop = false;
bool bdrop = false;

void move(pair<int,int> *a,pair<int,int> *b,int opt){

  int &rx = (*a).x, &ry = (*a).y;
  int &bx = (*b).x, &by = (*b).y;

  if(opt == 0){//왼쪽
    for(int i=0 ; i<m;i++){
      if(g[rx][ry-1] == WALL || g[bx][by-1] == WALL) break;
      ry--,by--;
      if(rx == h.x && ry == h.y) rdrop = true,rx=bx,ry=by;
      if(bx == h.x && by == h.y) bdrop = true;
    }
    if(g[rx][ry-1] == WALL){
      while(1){
        if(g[bx][by-1] == WALL || (by-1 == ry && bx == rx)) break;
        by--;
        if(rx == h.x && ry == h.y) rdrop = true,rx=0,ry=0;
        if(bx == h.x && by == h.y) bdrop = true;
      }
    }
    if(g[bx][by-1] == WALL){
      while(1){
        if(g[rx][ry-1] == WALL || (ry-1 == by && rx == bx)) break;
        ry--;
        if(rx == h.x && ry == h.y) rdrop = true;
        if(bx == h.x && by == h.y) bdrop = true;
      }
    }
  }
  else if(opt == 1){//오른쪽
    for(int i=0 ;i<m ;i++){
      if(g[rx][ry+1] == WALL || g[bx][by+1] == WALL) break;
      ry++,by++;
      if(rx == h.x && ry == h.y) rdrop = true,rx=bx,ry=by;
      if(bx == h.x && by == h.y) bdrop = true;
    }
    if(g[rx][ry+1] == WALL){
      while(1){
        if(g[bx][by+1] == WALL || (by+1 == ry && bx == rx)) break;
        by++;
        if(rx == h.x && ry == h.y) rdrop = true,rx=0,ry=0;
        if(bx == h.x && by == h.y) bdrop = true;
      }
    }
    if(g[bx][by+1] == WALL){
      while(1){
        if(g[rx][ry+1] == WALL || (ry+1 == by && rx == bx)) break;
        ry++;
        if(rx == h.x && ry == h.y) rdrop = true;
        if(bx == h.x && by == h.y) bdrop = true;
      }
    }
  }
  else if(opt == 2){//위
    for(int i=0 ;i<n ;i++){
      if(g[rx-1][ry] == WALL || g[bx-1][by] == WALL) break;
      rx--,bx--;
      if(rx == h.x && ry == h.y) rdrop = true,rx=bx,ry=by;
      if(bx == h.x && by == h.y) bdrop = true;
    }
    if(g[rx-1][ry] == WALL){
      while(1){
        if(g[bx-1][by] == WALL || (bx-1 == rx && by == ry)) break;
        bx--;
        if(rx == h.x && ry == h.y) rdrop = true,rx=0,ry=0;
        if(bx == h.x && by == h.y) bdrop = true;
      }
    }
    if(g[bx-1][by] == WALL){
      while(1){
        if(g[rx-1][ry] == WALL || (rx-1 == bx && ry == by)) break;
        rx--;
        if(rx == h.x && ry == h.y) rdrop = true;
        if(bx == h.x && by == h.y) bdrop = true;
      }
    }
  }
  else{
    for(int i=0 ; i<n ; i++){//아래
      if(g[rx+1][ry] == WALL || g[bx+1][by] == WALL) break;
      rx++,bx++;
      if(rx == h.x && ry == h.y) rdrop = true,rx=bx,ry=by;
      if(bx == h.x && by == h.y) bdrop = true;
    }
    if(g[rx+1][ry] == WALL){
      while(1){
        if(g[bx+1][by] == WALL || (bx+1 == rx && by == ry)) break;
        bx++;
        if(rx == h.x && ry == h.y) rdrop = true,rx=0,ry=0;
        if(bx == h.x && by == h.y) bdrop = true;
      }
    }
    if(g[bx+1][by] == WALL){
      while(1){
        if(g[rx+1][ry] == WALL || (rx+1 == bx && ry == by)) break;
        rx++;
        if(rx == h.x && ry == h.y) rdrop = true;
        if(bx == h.x && by == h.y) bdrop = true;
      }
    }
  }
}



int go(pair<int,int> r, pair<int,int> b,int cnt){
  if(cnt > 10) return INF;
  pair<int,int> R,B;

  int ans = INF;
  for(int i=0 ;i<4 ;i++){
    R = r, B = b;
    move(&R,&B,i);
    if(bdrop){
      bdrop = rdrop = false;
      continue;
    }
    if(rdrop){
      bdrop = rdrop = false;
      return cnt;
    }
    if(R==r && B==b) continue;
    ans = min(ans,go(R,B,cnt+1));
  }

  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  char c;
  for(int i=0 ;i<n;i++)
    for(int j=0 ;j<m ;j++){
      cin >> c;
      if(c == '#') g[i][j] = WALL;
      else if(c == 'O') h.x = i,h.y = j;
      else if(c == 'R') r.x = i,r.y = j;
      else if(c == 'B') b.x = i,b.y = j;
    }
  int ans = go(r,b,1);
  if(ans == INF) cout << -1 << '\n';
  else cout << ans << '\n';

  return 0;
}
