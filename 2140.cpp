#include <iostream>
using namespace std;

int dx[8] = {0, 0,1, 1,1,-1,-1,-1};
int dy[8] = {1,-1,1,-1,0, 1, 0,-1};
char maze[101][101]={0,};
int n,cnt=0;

void check(int x, int y){

  bool flag = false;
  for(int i=0 ;i<8;i++){
    char &c = maze[x+dx[i]][y+dy[i]];
    if(c == '&'&& x >=2 && y>=2 && x<=n-3 && y<=n-3){ flag = true;break;}
    if(c =='0'){flag = false;break;}
    if(c >='1' && c<='9') flag = true;
  }
  if(flag){
    for(int i=0 ;i<8;i++){
      char &c = maze[x+dx[i]][y+dy[i]];
      if(c >='1' && c<='9') c-=1;
    }
    if(maze[x][y]!='*') cnt++;
    maze[x][y] = '*';
  }
  else{
    for(int i=0;i<8;i++){
      char &c = maze[x+dx[i]][y+dy[i]];
      if(c=='&' &&x+dx[i] >=2 && y+dy[i]>=2 && x+dx[i]<=n-3 && y+dy[i]<=n-3){
        c = '*';
        cnt++;
      }
    }
    maze[x][y] = '&';
  }
}

int main(){

  cin >> n;
  for(int i=0 ;i<n;i++)
    for(int j=0 ;j<n;j++)
      cin >> maze[i][j];

  for(int i= 1;i<n-1;i++)
    for(int j=1 ;j<n-1;j++)
      check(i,j);
      // for(int i=0 ;i<n;i++){
      //   for(int j=0 ;j<n;j++)
      //     cout << maze[i][j];
      //   cout << endl;
      //   }
  cout << cnt << endl;

  return 0;
}
