#include <cstdio>

#define ABS(x) x<0?-x:x
int main(){

	int n,a,s1=0,s2=0;
	scanf("%d",&n);
	for(int i=0 ;i<n;i++) scanf("%d",&a),s1+=ABS(a);
	for(int i=0 ;i<n;i++) scanf("%d",&a),s2+=ABS(a);
	printf("%d\n",s1+s2);
	return 0;
}