#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int,int>

vector<pii> go[10001],back[10001];
int d[10001];
int ind[10001];

int main(){
  ios_base::sync_with_stdio(0);
  int n,m;
  int start,last;
  cin >> n >> m;

  for(int i=0 ;i<m;i++){
    int x,y,t;
    cin >> x >> y >> t;
    go[x].push_back(pii(y,t));
    back[y].push_back(pii(x,t));
    ind[y]++;
  }

  cin >> start >> last;

  queue<int> q;
  q.push(start);

  while(q.size()){
    int cur = q.front();
    q.pop();
    for(pii nx : go[cur]){
      d[nx.first] = max(d[nx.first],d[cur] + nx.second);
      ind[nx.first]--;
      if(!ind[nx.first]) q.push(nx.first);
    }
  }
  int visit[10001]={0,};
  q.push(last);
  int cnt = 0;
  while(q.size()){
    int cur = q.front();
    q.pop();
    for(pii nx : back[cur]){
      if(d[cur] - nx.second == d[nx.first]){
        cnt++;
        if(!visit[nx.first]){
          visit[nx.first]=1;
          q.push(nx.first);
        }
      }
    }
  }

  cout << d[last] << '\n' << cnt << '\n';
  return 0;
}
