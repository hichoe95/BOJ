#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ind[10001];
int w[10001];
vector<int> v[10001];
int t[10001];

int main(){

  int n;
  cin >> n;

  for(int i=1,m ;i<=n ;i++){
    cin >> w[i] >> m;
    for(int j=0 ;j<m ; j++){
      int x;
      cin >> x;
      v[x].push_back(i);
      ind[i]++;
    }
  }
  queue<int> q;
  for(int i=1 ; i<=n ; i++)
     if(!ind[i]){
       q.push(i);
       t[i] = w[i];
     }

  while(q.size()){
    int cur = q.front();
    q.pop();
    for(int i : v[cur]){
      t[i] = max(t[i], w[i]+t[cur]);
      ind[i]--;
      if(!ind[i]) q.push(i);
    }
  }
  for(int i=1 ;i<=n;i++) t[n] = max(t[n],t[i]);
  cout << t[n] << '\n';

  return 0;
}
