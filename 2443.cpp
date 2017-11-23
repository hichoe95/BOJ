#include <stdio.h>

void print_star(int n){
  int k=1;
  for(int i=n; i>=1;i--){
    for(int x=0 ;x<(2*n-1)/2-i+1; x++) printf(" ");
    for(int j=1 ; j<= i*2-1 ; j++) printf("*");
    puts("");
  }

}

int main(){
  int n;
  scanf("%d",&n);
  print_star(n);

  return 0;
}
