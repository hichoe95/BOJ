#include <stdio.h>

int main()
{
  int num[100001];
  int n,sum=0, i,max = -999999;

  scanf("%d ",&n);

  for(i = 1 ; i <= n; i++)
    scanf(" %d",&num[i]);

  for(i=1 ;i <=n;i++){
    sum += num[i];
    if(max < sum)
      max = sum;
    if(sum<0)
      sum = 0;
  }
  printf("%d\n",max);
  return 0;
}
