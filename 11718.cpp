#include <stdio.h>

int main(void){
  char c[111];

  while(scanf("%[^\n]\n",c)==1)
    printf("%s\n",c);

  return 0;
}
