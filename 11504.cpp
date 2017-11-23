#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int MakeNum(int m,vector<int> v){
  int NUM=0;
  for(int i : v){
    NUM*=10;
    NUM+=i;
  }
  return NUM;
}

int main(){
  ios_base::sync_with_stdio(0);

  int t;
  cin >> t;

  while(t--){
    int n,m,X=0,Y=0,cnt=0;
    cin >> n >> m;
    for(int i=0 ;i<m ;i++){
      int x;
      cin >> x;
      X*=10,X+=x;
    }
    for(int i=0 ;i<m ; i++){
      int y;
      cin >> y;
      Y*=10,Y+=y;
    }

    vector<int> v(n);
    for(int i=0 ;i<n; i++) cin >> v[i];//돌림판 입력
    for(int i=0 ;i<m ; i++) v.push_back(v[i]); // 마지막 m자리 채우기위해서 뒤에 앞자리 더 붙여줌

    for(int i=0 ;i<n; i++){
      vector<int> k(m);
      for(int j=0 ;j<m;j++) k[j] = v[i+j];
      int NUM = MakeNum(m,k);
      if(NUM >= X && NUM <= Y) cnt++;
    }
    cout << cnt << '\n';

  }

  return 0;
}
