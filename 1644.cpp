#include <iostream>
using namespace std;

int a[1000];

int main(){
  ios_base::sync_with_stdio(0);
  int n,m;
  cin >> n;

  int l=0,r=0,length=1000000009;

  while(l<=n && r<=n){
    int sum = a[r] - a[l-1];
    if(sum == m){
      if(length > r-l+1) length = r-l+1;
      r++;
    }
    else if(sum<m) r++;
    else if(sum>m) l++;
  }

  cout << length << '\n';
  return 0;
}
