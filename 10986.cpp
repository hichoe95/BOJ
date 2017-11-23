#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0);
  int n ,m;
  cin >> n >> m;
  vector<ll> v(n);
  vector<ll> cnt(m);
  cnt[0]=1;
  for(int i=0 ;i<n;i++){
    cin >> v[i], v[i] += (i?v[i-1]:0);
    cnt[v[i]%m]++;
  }
  ll ans=0;
  for(ll i : cnt) ans+=(i*(i-1))/2;

  cout << ans << '\n';

  return 0;
}
