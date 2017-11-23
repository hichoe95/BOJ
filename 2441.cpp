#include <cstdio>

int main(){
	int n,i,j,k;
	scanf("%d",&n);

	for(int i=0 ;i<n;i++){
		for(j=0; j<i;j++) printf(" ");
		for(k=0; k<n-j;k++) printf("*");
		puts("");
	}
	return 0;
}