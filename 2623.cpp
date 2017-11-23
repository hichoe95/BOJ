#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[1001];
vector<int> ans;
int ind[1001];

void dfs(int x){
  ind[x]-=1;
  ans.push_back(x);

  for(int i : v[x]){
    if(!(--ind[i])) dfs(i);
  }
}

int main(){
  ios_base::sync_with_stdio(0);

  int n,m;
  cin >> n >> m;

  for(int i=0 ;i<m;i++){
    int k,from,to;
    cin >> k;
    cin >> from;
    for(int j=0 ;j<k-1 ; j++){
      cin >> to;
      v[from].push_back(to);
      from = to;
      ind[to]++;
    }
  }

  for(int i=0 ; i<n;i++)
    if(!ind[i+1]) dfs(i+1);

  if(ans.size() < n) cout <<"0\n";
  else{
    for(int i : ans) cout << i<< '\n';
  }
  return 0;
}
