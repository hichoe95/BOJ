#include <iostream>
#include <vector>
using namespace std;

int n,m,k;
vector<long long> v;
vector<long long> tree;

long long sum(int k){
  long long ans = 0;
  while(k>0){
    ans += tree[k];
    k-=(k&-k);
  }
  return ans;
}

void upd(int i,int s){
  while(i<tree.size()){
    tree[i] += s;
    i+=(i&-i);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  v.resize(n+1);
  tree.resize(n+1);
  for(int i=1 ;i<=n;i++) cin >> v[i],upd(i,v[i]);
  for(int i=0 ;i<m+k ; i++){
    int a,b,c;
    cin >> a >> b >> c;
    if(a==1){
      int k = c - v[b];
      v[b] = c;
      upd(b,k);
    }
    else cout << sum(c) - sum(b-1) << '\n';
  }

  return 0;
}
