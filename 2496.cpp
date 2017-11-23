#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,t,k,cnt,M;
pair<int,int> temp;
vector< pair<int,int> > dia;

int inRange(x,y,k,checkX,checkY){
  if(checkX>=x && checkX<=x+k && checkY>=y-k && checkY<=y)
    return 1;
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> t >> k;

  int x,y;
  for(int i=0 ;i<t ;i++){
    cin >> x >> y;
    dia.push_back(pair<int,int>((x-y),(x+y)));
  }

  for(pair<int,int> p : dia){
    x=p.first, y=p.second;
    for(int i=0 ;i <= k; i++){
      for(pair<int,int> p2 : dia){
        if(inRange(x,y+i,k,p2.first,p2.second))
          cnt++;
      }
      if(cnt> M){
        temp = p;
        M=cnt;
      }
    }
  }


  return 0;
}
