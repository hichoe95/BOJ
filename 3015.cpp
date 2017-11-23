#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define ll long long

int  main(){
  ios_base::sync_with_stdio(0);
  ll ans=0,n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0 ; i<n ;i++) cin >> a[i];

  stack<pair<ll,ll> > s;

  for(int i=0 ;i<n; i++){
    pair<ll,ll> p = {a[i],1};
    while(!s.empty()){
      if(s.top().first <= a[i]){
        ans += s.top().second;
        if(s.top().first == a[i]) p.second += s.top().second;
        s.pop();
      }
      else break;
    }
    if(!s.empty()) ans+=1LL;
    s.push(p);
  }

  cout << ans << '\n';

  return 0;

}
