#include <iostream>
using namespace std;

int a[100001];

int main(){
  ios_base::sync_with_stdio(0);
  int n,m;
  cin >> n >> m;

  for(int i=1 ;i<=n;i++){
    cin >> a[i];
    a[i] += a[i-1];
  }

  int l=0,r=0,length=100000009;
  while(l<=n && r<=n){
    int sum = a[r] - a[l-1];
    if(sum >= m){
      if(length > r-l+1) length = r-l+1;
      l++;
    }
    else if(sum<m) r++;
    else if(sum>m) l++;
  }
  if(length == 100000009) cout << 0 << '\n';
  else cout << length << '\n';
  return 0;
}
