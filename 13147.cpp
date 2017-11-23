#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector<int> v[10001];
int visited[10001];
int finished[10001];

bool dfs(int x){
  bool flag = true;
  visited[x] = 1;
  for(int nx : v[x]){
    if(!visited[nx]) flag = dfs(nx);
    if(flag == false) break;
    else if(finished[nx] == 0) return false;
  }
  finished[x] = 1;
  return flag;
}

int main(){
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;

  map<string,int> m;

  for(int i=0 ; i<n ; i++){
    string a,ine,b;
    cin >> a >> ine >> b;
    if(m.find(a) == m.end()) m[a] = m.size()+1;
    if(m.find(b) == m.end()) m[b] = m.size()+1;
    if(ine == ">") v[m[a]].push_back(m[b]);
    else v[m[b]].push_back(m[a]);
  }

  int sz = m.size();
  for(int i=0 ;i<sz ; i++){
    if(!visited[i+1]){
      if(!dfs(i+1)){
        cout << "impossible\n";
        return 0;
      }
    }
  }

  cout << "possible\n";

  return 0;
}
