#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1234567

long long int d[15][1002];

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;

  for(int i=3 ;i<=12;i++)
    d[i][1] = 1;

  for(int j=2 ; j<=1000 ; j++)
    for(int i=3 ; i<13 ; i++){
      if(i==3 || i==6 || i==9 || i==12){
        d[i][j] = (d[i+1][j-1]+d[i-3][j-1]+d[i+3][j-1])%MOD;
        continue;
      }
      if(i==5 || i==8 || i==11){
        d[i][j] = (d[i-1][j-1]+d[i-3][j-1]+d[i+3][j-1])%MOD;
        continue;
      }
      d[i][j] = (d[i-1][j-1]+d[i-3][j-1]+d[i+3][j-1]+d[i+1][j-1])%MOD;
    }

  while(t--){
    int n;cin >> n;
    long long int sum=0;
    for(int i=3;i<13;i++){
      sum+=d[i][n];
      sum%=MOD;
    }
    cout << sum << '\n';
  }
  return 0;
}
