#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

struct matrix{
  int co[50];
}matrix[4];
int flag = 1;
bool check(int a){
  for(int i=0 ;i<50 ;i++)
    if(matrix[a].co[i]>0 && matrix[a].co[i] <10) return false;

  return true;
}

bool compare(int a,int b){//a<b true, a>b false

  for(int i = 49 ; i>=0 ; i--){
    if(flag==1) cout << i << " " << matrix[a].co[i] << " " <<matrix[b].co[i] << endl;
    if(matrix[a].co[i] < matrix[b].co[i]){
      return true;
    }
    else if(matrix[a].co[i] > matrix[b].co[i]) return false;
  }
  flag =2;
}

void de(int a,int b){//a-b
  bool down = false;

  for(int i=0 ;i<50 ; i++){
    if(down){
      if(matrix[a].co[i]-1 >=0 ){
        matrix[a].co[i]-=1;
        down = false;
      }
      else{
        matrix[a].co[i] = 9;
        down = true;
      }
    }
    if(matrix[a].co[i] - matrix[b].co[i] >=0){
      matrix[a].co[i] -= matrix[b].co[i];
    }
    else{
      matrix[a].co[i] = matrix[a].co[i] - matrix[b].co[i] + 10;
      down = true;
    }

  }

}


int main(){

  stack<int> s;
  string num;

  for(int i=0 ;i<4 ; i++)
   for(int j=0 ;j<50 ;j++)
    matrix[i].co[j] = 0;

  for(int i=0 ;i<2 ; i++){
    for(int j=0 ; j<2 ; j++){
      cin >> num;
      int sz = num.size();
      for(int k=sz-1 ; k>=0 ; k--) matrix[i+j].co[sz-k-1] = num[k]-'0';
    }
  }

  while(1){
    if(compare(0,1) || compare(2,3)){
      de(1,0);
      de(3,2);
      s.push(1);
    }
    else{
      de(0,1);
      de(2,3);
      for(int k=2 ; k>=0 ; k--) cout << matrix[0].co[k];
      cout << endl;
      s.push(0);
    }
    if(check(1) && check(2)) break;
  }
  while(s.size()){
    cout << s.top();
    s.pop();
  }

  return 0;
}
