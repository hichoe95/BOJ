#include <iostream>
#include <vector>
using namespace std;
#define pii pair<int,int>
#define INF 1e9

int main(){
  ios_base::sync_with_stdio(false);
  int n,m,d[500]={0,};
  cin >> n >> m;

  vector<pii> v[500];

  for(int i=0 ;i<m ;i++){
    int a,b,c;
    cin >> a >> b >> c;
    v[a-1].push_back(pii(b-1,c));
  }
  for(int i=1 ;i<n ;i++) d[i] = INF;
  bool mcycle = false;
  for(int i=0 ;i<n ; i++){
    for(int j=0 ; j<n ; j++){
      for(auto nx : v[j]){
        int next = nx.first, cost = nx.second;
        if(d[j]!=INF && d[next] > d[j] + cost){
          d[next] = d[j] + cost;
          if(i == n-1) mcycle = true;
        }
      }
    }
  }

  if(mcycle) cout << -1 << '\n';
  else for(int i=1 ; i<n; i++) cout << (d[i]==INF ? -1 : d[i]) << '\n';

  return 0;
}
