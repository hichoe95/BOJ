#include <iostream>
using namespace std;

int gcd(int a,int b){
  if(!b)
    return a;
  return gcd(b,a%b);
}
int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--){
    int a,b,g;
    cin >> a >> b;
    g=gcd(a,b);
    cout << g*(a/g)*(b/g) << '\n';
  }
  return 0;
}
