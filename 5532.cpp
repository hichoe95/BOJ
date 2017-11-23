#include <iostream>
#include <cmath>
using namespace std;

int main(){
  double l,a,b,c,d;
  cin >> l >> a >> b >> c >> d;
  cout << (int)floor(l-(a/c > b/d ? a/c:b/d));
  return 0;
}
