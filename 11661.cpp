#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
  ll A,B,C,x1,x2,y1,y2;
  cin >> A >> B >> C >> x1 >> x2 >> y1 >> y2;
  C = -C;
  if(A==0 && B==0 && C==0){
    ll cnt = (x2-x1+1)*(y2-y1+1);
    cout << cnt << '\n';
    return 0;
  }

  if(A==0 && B==0 && C!=0){
    cout << 0 << "\n";
    return 0;
  }

  if(A<0){
    A = -A;
    x2^=x1;
    x1^=x2;
    x2^=x1;
    x1 = -x1;
    x2 = -x2;
  }
  if(B<0){
    B = -B;
    y1^=y2;
    y2^=y1;
    y1^=y2;
    y1 = -y1;
    y2 = -y2;
  }

  if(A==0){
    if( (abs(C)%abs(B))>0){
      cout << 0 << '\n';
      return 0;
    }
    else{
      if((C/B) >= y1 && (C/B) <=y2)
        cout << x2-x1+1 << '\n';
      else cout << 0 << '\n';
      return 0;
    }
  }
  if(B==0){
    if((abs(C)%abs(A))>0){
      cout << 0 << '\n';
      return 0;
    }
    else{
      if((C/A) >= x1 && (C/A) <= x2)
        cout << y2-y1+1 << '\n';
      else cout << 0 << '\n';
      return 0;
    }
  }

  ll r0=A,r1=B,s0=1,s1=0,t0=0,t1=1;

  while(r1){
    ll q = r0/r1;
    ll s,t,r;
    r = r0 - r1*q;
    s = s0 - s1*q;
    t = t0 - t1*q;
    s0 = s1,s1 = s;
    t0 = t1,t1 = t;
    r0 = r1,r1 = r;
  }

  if(C%r0!=0){
    cout << 0 << '\n';
    return 0;
  }

  ll g = r0;
  //cout << s0 << " " << t0 << " " << r0 << endl;
  ll x = s0*(C/g), y = t0*(C/g);
  //cout << x << " " << y << endl;
  //printf("%lld <= x <= %lld \n%lld <= y <= %lld\n",x1,x2,y1,y2);
  //printf("%lldx + %lldy = %lld , %lld\n",A,B,C,g);
  ll b = B/g,a=A/g;
  //cout << "b : " << b << " a : " << a << endl;
  double new_x1 = x1 - x, new_x2 = x2 - x;
  double new_y1 = y1 - y, new_y2 = y2 - y;

  new_x1/=b;
  new_x2/=b;
  new_y1/=a;
  new_y2/=a;

  //cout << new_x1 << " " << new_x2 << " " << new_y1 << " " << new_y2 << endl;
  int xx1 = ((int)ceil(new_x1)),xx2 = ((int)floor(new_x2));
  int yy1 = ((int)ceil(new_y1)),yy2 = ((int)floor(new_y2));
  yy1^=yy2;
  yy2^=yy1;
  yy1^=yy2;
  yy1=-yy1;
  yy2=-yy2;
  //cout << xx1 << " " << xx2 << " " << yy1 << " " << yy2 << endl;
  int cnt = min(xx2,yy2)-max(xx1,yy1)+1;
  cout << (cnt>=0? cnt : 0) << endl;

  return 0;
}
