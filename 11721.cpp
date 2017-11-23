#include <cstdio>
#include <cstring>
int main(){
	char c[101];
	scanf("%s",c);
	int len = strlen(c);
	int r=len/10;
	for(int i=0 ;i<r;i++){
		for(int j=i*10 ;j<i*10+10 ;j++)
			printf("%c",c[j]);
		printf("\n");
	}
	for(int i=10*r ; i<len ; i++)
		printf("%c",c[i]);
	puts("");
	return 0;
}