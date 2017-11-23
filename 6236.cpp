#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> v;

bool check(int money){
  int cnt=1;
  int M = money;

  for(int i: v){
    if(M-i <0) M = (money-i),cnt++;
    else M-= i;
  }
  return (cnt > m);
}

int main(){

  ios_base::sync_with_stdio(0);

  cin >> n >> m;
  v.resize(n,0);
  int M=-1;
  for(int i=0 ;i<n ;i++) cin >> v[i],M = (v[i]>M?v[i]:M);


  int l = M, r = 1000000000;

  while(l<=r){
    int c = (l+r)/2;
    check(c) ? l = c+1 : r = c-1;
  }

  cout << l << endl;

  return 0;
}
