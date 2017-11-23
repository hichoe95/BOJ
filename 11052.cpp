#include <iostream>
#include <algorithm>
using namespace std;

int p[1001];
int d[1001];

int maxPrice(int n){
  if(d[n])
    return d[n];

  d[n] = p[n];

  for(int i = 0 ; i < n ; i++){
    int temp = maxPrice(n-i);
    if(d[n] < temp+p[i])
      d[n] = temp + p[i];
  }

  return d[n];
}

int main(){
  ios_base::sync_with_stdio(false);

  int n;

  cin >> n;

  for(int i=1 ; i<=n ;i++)
    cin >> p[i];

  cout << maxPrice(n) << '\n';
  return 0;
}
