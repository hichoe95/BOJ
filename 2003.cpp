#include <iostream>
using namespace std;

int a[10001];

int main(){
  ios_base::sync_with_stdio(0);
  int n,m;
  cin >> n >> m;

  for(int i=1 ;i<=n;i++){
    cin >> a[i];
    a[i] += a[i-1];
  }

  int l=0,r=0,cnt=0;

  while(l<=n && r<=n){
    int sum = a[r] - a[l-1];
    if(sum == m) cnt++,r++;
    else if(sum<m) r++;
    else if(sum>m) l++;
  }

  cout << cnt << '\n';
  return 0;
}
