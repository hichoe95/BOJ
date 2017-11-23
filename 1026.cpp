#include <cstdio>
#include <algorithm>

bool cmp(const int &a, const int &b){
  return a>b;
}

int main(){
  int a[50],b[50],n,i,ans=0;
  scanf("%d",&n);
  for(i=0 ;i<n;i++) scanf("%d",&a[i]);
  for(i=0 ;i<n;i++) scanf("%d",&b[i]);
  std::sort(a,a+n);
  std::sort(b,b+n,cmp);
  for(i=0 ;i<n;i++) ans+=a[i]*b[i];
  printf("%d\n",ans);
  return 0;
}
