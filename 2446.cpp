#include <stdio.h>

void print_star(int n){
  int k=1;
  for(int i=n; i>=1;i--){
    for(int x=0 ;x<(2*n-1)/2-i+1; x++) printf(" ");
    for(int j=1 ; j<= i*2-1 ; j++) printf("*");
    puts("");
  }

}
void print_star1(int n){
  int k=1;
  for(int i=2; i<=n;i++){
    for(int x=0 ;x<(2*n-1)/2-i+1; x++) printf(" ");
    for(int j=1 ; j<= i*2-1 ; j++) printf("*");
    puts("");
  }

}

int main(){
  int n;
  scanf("%d",&n);
  print_star(n);
  print_star1(n);

  return 0;
}

