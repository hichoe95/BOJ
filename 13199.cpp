#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);

  int t;
  cin >> t;

  while(t--){
    int p,m,f,c;
    cin >> p >> m >> f >> c;

    int coupon = (((m/p)*c)/f)*c + ((m/p)*c)%f;
    int chick = 0;
    while(coupon){
      chick += coupon/f;
      coupon = (coupon/f)*c + coupon%f;
      if(coupon < f) break;
    }

    cout << chick << '\n';

  }

  return 0;
}
