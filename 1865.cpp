#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9
#define pii pair<int,int>

int main(){
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;

  while(t--){
    int n,m,w,d[500]={0,};
    cin >> n >> m >> w;

    vector<pii> v[500];

    for(int i=0 ;i<m ; i++){
      int s,e,t;
      cin >> s >> e >> t;
      v[s-1].push_back(pii(e-1,t));
      v[e-1].push_back(pii(s-1,t));
    }
    for(int i=0 ;i<w ;i++){
      int s,e,t;
      cin >> s >> e >> t;
      v[s-1].push_back(pii(e-1,-t));
    }

    for(int i=1 ; i<n ;i++) d[i] = INF;

    bool mcycle = false;

    for(int i=0 ;i<n ; i++){
      for(int j=0 ;j<n; j++){
        for(auto &nx : v[j]){
          int next = nx.first , cost = nx.second;
          if(d[j]!=INF && d[next] > d[j] + cost){
            d[next] = d[j] + cost;
            if(i == n-1) mcycle = true;
          }
        }
      }
    }
    cout << (mcycle ? "YES" : "NO") << '\n';
  }

  return 0;
}
