#include <cstdio>
#include <deque>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int g[100][100];
int d[100][100];

int main(){

  int n,m;
  scanf("%d %d",&m,&n);

  for(int i=0 ;i<n;i++)
    for(int j=0 ; j<m;j++)
      scanf("%1d",&g[i][j]),d[i][j] = -1;

  deque<pair<int,int> > dq;

  dq.push_back(make_pair(0,0));
  d[0][0] = 0;

  while(dq.size()){
    int x = dq.front().first;
    int y = dq.front().second;
    dq.pop_front();

    for(int i=0 ;i<4 ;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx>=0 && nx <n && ny>=0 && ny<m){
        if(d[nx][ny] == -1){
          if(g[nx][ny]){
            d[nx][ny] = d[x][y] +1;
            dq.push_back(make_pair(nx,ny));
          }
          else{
            d[nx][ny] = d[x][y];
            dq.push_front(make_pair(nx,ny));
          }
        }
      }
    }
  }

  printf("%d\n",d[n-1][m-1]);

  return 0;
}
