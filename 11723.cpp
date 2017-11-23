#include <cstdio>
#include <cstring>

int main(){

	int M,arr=0;
	scanf("%d",&M);

	while(M--){
		char s[10];
		int n;
		scanf("%s",s);

		if(!strcmp(s,"add")){
			scanf("%d",&n);
			arr |= (1<<n);
		}
		else if(!strcmp(s,"remove")){
			scanf("%d",&n);
			arr&=~(1<<n);
		}
		else if(!strcmp(s,"check")){
			scanf("%d",&n);
			if(arr&(1<<n)) puts("1");
			else puts("0");
		}
		else if(!strcmp(s,"toggle")){
			scanf("%d",&n);
			arr ^= (1<<n);
		}
		else if(!strcmp(s,"all")){
			arr |= ~(1<<21);
		}
		else if(!strcmp(s,"empty")){
			arr=0;
		}
	}

	return 0;

}