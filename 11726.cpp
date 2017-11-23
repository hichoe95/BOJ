#include <iostream>
#include <algorithm>
using namespace std;
long long int d[1001];
long long int tile(int n){
  if(n<=1)
    return 1;
  if(n<=2)
    return 2;

  if(d[n])
    return d[n];

  d[n] = (tile(n-1) + tile(n-2))%10007;

  return d[n];


}

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  cout << tile(n) << '\n';

  return 0;
}
