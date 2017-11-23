#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree[100001];
int parent[100001];

queue<int> q;

void bfs(){
  q.push(1);

  while(!q.empty()){
    int next = q.front();
    q.pop();

    for(int i : tree[next]){
      if(!parent[i]){
        q.push(i);
        parent[i] = next;
      }
    }
  }

}

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1 ;i<n;i++){
    int a,b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }


  bfs();

  for(int i=2; i<=n;i++)
    cout << parent[i] << '\n';

  return 0;
}
