#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int w[501];
int ind[501];
vector<int> v[501];
int d[501];

int main(){
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;

  for(int i=1 ; i<=n ; i++){
    int x;
    cin >> w[i] >> x;
    while(x!=-1){
      v[x].push_back(i);
      ind[i]++;
      cin >> x;
    }
  }

  queue<int> q;
  for(int i=1 ; i<=n ;i++) if(!ind[i]){
    q.push(i);
    d[i] = w[i];
  }

  while(q.size()){
    int cur = q.front();
    q.pop();

    for(int nx : v[cur]){
      d[nx] = max(d[nx],d[cur] + w[nx]);
      ind[nx]--;
      if(!ind[nx]) q.push(nx);
    }
  }

  for(int i=1 ;i<=n;i++) cout << d[i] << '\n';


  return 0;
}
