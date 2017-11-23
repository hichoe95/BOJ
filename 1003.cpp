#include <cstdio>

int d[41];

int fibonacci(int n) {
    if (n==0) return 1;
    else if (n==1) return 1;
    else if(d[n]) return d[n];
    else return d[n] = fibonacci(n-1) + fibonacci(n-2);
}

int main(){
  int t;
  scanf("%d",&t);
  d[0] = 1;
  d[1] = 1;

  while(t--){
    int n;
    scanf("%d",&n);
    fibonacci(n);
    if(!n) printf("1 0\n");
    else if(n==1) printf("0 1\n");
    else printf("%d %d\n",d[n-2],d[n-1]);

  }
  return 0;
}
