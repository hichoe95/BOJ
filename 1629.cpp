#include <cstdio>
#define ll long long

ll POW(ll a, ll b, ll MOD){

  ll r = 1;
  a%=MOD;

  while(b){
    if(b&1) r = (r*a)%MOD;
    a = (a*a)%MOD;
    b>>=1;
  }
  return r;
}

int main(){
  ll a,b,c;
  scanf("%lld %lld %lld",&a,&b,&c);
  printf("%lld",POW(a,b,c));
  return 0;
}
