#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

ll n,a,b,cnt;
ll A[1001],B[1001];
vector<ll> na(1,0), nb(1,0);
int main(){
  ios_base::sync_with_stdio(0);

  cin >> n >> a >> b;

  for(int i=1 ;i<=a ; i++) cin >> A[i];
  for(int i=1 ;i<=b ; i++) cin >> B[i];

  for(int i=1 ;i<=a ;i++) A[i] += A[i-1];
  for(int i=1 ;i<=b ;i++) B[i] += B[i-1];

  for(int i=1 ; i<=a ;i++)
    for(int j=0 ;j<a-1 ; j++){
      ll sum = 0;
      if((i+j)/(a+1)) sum = A[(i+j)%a] + A[a] - A[i-1];
      else sum = A[i+j] - A[i-1];
      if(sum <= n) na.push_back(sum);
    }

  for(int i=1 ; i<=b ;i++)
    for(int j=0 ;j<b-1 ; j++){
      ll sum = 0;
      if((i+j)/(b+1)) sum = B[(i+j)%b] + B[b] - B[i-1];
      else sum = B[i+j] - B[i-1];
      if(sum <= n) nb.push_back(sum);
    }
  na.push_back(A[a]);
  nb.push_back(B[b]);
  sort(na.begin(),na.end());
  sort(nb.begin(),nb.end());

  // for(int i : na) cout << "A : " << i << endl;
  // for(int i : nb) cout << "B : " << i << endl;

  ll l=0, r = nb.size()-1;
  ll sz = na.size();

  while(l<sz && r>=0){
    ll sum = na[l] + nb[r];
    if(sum == n){
      ll temp_l = na[l],cnt_l=0;
      while(temp_l == na[l] && l<sz) cnt_l++,l++;

      ll temp_r = nb[r],cnt_r=0;
      while(temp_r == nb[r] && r>=0) cnt_r++,r--;

      // cout << "l : " << l << endl;
      // cout << "r : " << r << endl;

      cnt+=(cnt_r*cnt_l);
    //  cout << "cnt : " << cnt << endl;
    }
    else if(sum > n) r--;
    else l++;
  }

  cout << cnt << endl;

  return 0;
}
