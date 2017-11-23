#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[1000001];
bool ed[1000001];
int n,cnt;

void check(int cur,int p){
  int flag = 0;
  for(int i : tree[cur])
    if(i!=p){
      check(i,cur);
      if(!ed[i]) flag = 1;
    }

    if(flag) ed[cur] = true , cnt++;
} 


int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  for(int i=0,a,b ;i<n-1;i++){
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  check(1,0);
  cout << cnt << endl;
  return 0;
}

