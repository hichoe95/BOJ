#include <iostream>
#include <cstring>
using namespace std;

char puyo[15][15];
int visited[15][15];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int range(int x,int y){
  if(x==-1 || x==12 || y==-1 || y==6)
    return 0;
  return 1;
}

int check(int x, int y){

  int sum=1;
  if(visited[x][y])
    return 0;
  visited[x][y]=1;
  for(int i=0 ; i<4 ;i++){
    if(range(x+dx[i],y+dy[i]) && !visited[x+dx[i]][y+dy[i]]){
      if(puyo[x][y]!='.' && puyo[x][y] == puyo[x+dx[i]][y+dy[i]])
        sum+=check(x+dx[i],y+dy[i]);
    }
  }
  return sum;
}

void erase(int x, int y){
  visited[x][y]=1;
  for(int i=0 ; i<4 ;i++){
    if(range(x+dx[i],y+dy[i]) && !visited[x+dx[i]][y+dy[i]]){
      if(puyo[x][y] == puyo[x+dx[i]][y+dy[i]]){
        erase(x+dx[i],y+dy[i]);
        puyo[x+dx[i]][y+dy[i]] = '.';
      }
    }
  }
  puyo[x][y] = '.';
}

void drop(){
  int k,m,n,i,j;
  for(k=0 ; k<12 ; k++){
    for(j=0 ; j<6 ;j++){
      if(puyo[k][j] == '.'){
        for(i=k+1 ; i<12;i++){
          if(puyo[i][j]!='.'){
            break;
          }
        }
        for(m=i,n=k;m<12;n++,m++){
          if(puyo[m][j]!='.'){
            puyo[n][j]=puyo[m][j];
            puyo[m][j]='.';
          }
        }
      }
    }
  }
}

int main(){

  ios_base::sync_with_stdio(false);
  int pop=0,cnt=0,temp;
  for(int i=11 ; i>=0 ; i--){
    for(int j=0 ; j<6 ;j++)
    cin >> puyo[i][j];
  }


  while(1){
    for(int i=0 ;i<12 ;i++){
      for(int j=0; j<6 ; j++){
        temp=check(i,j);
        memset(visited,0,sizeof(visited));
        //cout << temp << endl;
        if((temp)>=4){
          cnt++;
          erase(i,j);
        }
        memset(visited,0,sizeof(visited));
      }

    }
    drop();
    if(cnt){
      //cout << "drop" << endl;
      pop+=1;
    }
    else
      break;
    cnt=0;
  }
  cout << pop << endl;

  return 0;
}
