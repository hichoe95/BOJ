#include <cstdio>

int main(){
	long long multi;
	int a,b,c,arr[10]={0,},i=0;
	scanf("%d %d %d",&a,&b,&c);
	multi = a* b* c;
	while(multi){
		arr[multi%10]++;
		multi/=10;
	}
	for(i=0 ;i<10 ;i++) printf("%d\n",arr[i]);

	return 0;
}