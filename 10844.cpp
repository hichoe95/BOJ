#include <iostream>
using namespace std;
#define inf 1000000000

long long int d[101][10];

long long int dlclstn(int n,int i){

  if(n<=1 || d[n][i])
    return d[n][i];

  if(i!=0) d[n][i] += dlclstn(n-1,i-1);
  if(i!=9) d[n][i] += dlclstn(n-1,i+1);
  d[n][i]%=inf;

  return d[n][i];
}

int main(){
  ios_base::sync_with_stdio(false);

  int n;

  cin >> n;

  for(int i=1 ; i<10 ; i++) d[1][i] = 1;

  long long int ans=0;

  for(int i=0 ;i<10 ; i++){
    ans+=dlclstn(n,i);
    ans%=inf;
  }

  cout << ans << '\n';

  return 0;
}
