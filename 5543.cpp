#include <cstdio>
#define INF 1e9

int main(){
  int a,b;
  a=b=INF;
  for(int i=0,x;i<3;i++){
    scanf("%d",&x);
    a = (a>x ? x : a);
  }
  for(int i=0,x;i<2;i++){
    scanf("%d",&x);
    b = (b>x ? x : b);
  }
  printf("%d\n",a+b-50);
  return 0;
}
