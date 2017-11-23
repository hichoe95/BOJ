#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 1e9+7

int main(){

  ios_base::sync_with_stdio(0);

  int t;
  cin >> t;

  while(t--){
    int lim,n;
    ll ans=INF;
    vector<ll> a[4],s[2];
    cin >> lim >> n;
    for(int i=0 ;i<4 ;i++) a[i].resize(n+1);

    for(int i=0 ;i<4 ; i++)
      for(int j=0 ;j<n; j++)
        cin >> a[i][j];

    for(int i=0 ;i<2 ; i++)
      for(int j=0 ; j<n; j++)
        for(int k=0 ; k<n ; k++)
          s[i].push_back(a[i*2][j]+a[i*2+1][k]);

    for(int i=0 ;i<2 ; i++) sort(s[i].begin(),s[i].end());

    for(ll cur : s[0]){
      auto rest = lower_bound(s[1].begin(),s[1].end(),lim-cur);
      ll sum = *rest + cur;
      if(rest != s[1].end()){
        if(abs(ans-lim) > abs(sum-lim)) ans = sum;
        if(abs(ans-lim) == abs(sum-lim) && ans>sum) ans = sum;
      }
      if(rest != s[1].begin()){
        rest--,sum = *rest+cur;
        if(abs(ans-lim) > abs(sum-lim)) ans = sum;
        if(abs(ans-lim) == abs(sum-lim) && ans>sum) ans = sum;
      }
    }
    cout << ans << '\n';

  }

  return 0;
}
