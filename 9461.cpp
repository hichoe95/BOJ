#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int t,n;
  cin >> t;

  while(t--){
    cin >> n;
    long long d[101]={0};
    d[1]=1,d[2]=1,d[3]=1;
    for(int i=4 ; i<=n;i++)
      d[i] = d[i-3] + d[i-2];
    cout << d[n] << '\n';
  }
  return 0;
}
