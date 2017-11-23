#include <iostream>
using namespace std;

int main(){

  int a,b,c;
  cin >> a >> b >> c;

  c-=b;
  if(c<=0) cout << -1;
  else cout << a/c + 1;

  return 0;
}
