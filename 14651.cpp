#include <cstdio>
const long long MOD = 1e9+9;

int main(){
  int n;
  long long cnt=2;
  scanf("%d",&n);
  if(n==1) printf("0\n");
  else{
    while(n-->2)cnt=(cnt*3)%MOD;
    printf("%lld\n",cnt);
  }
  return 0;
}
