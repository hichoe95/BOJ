#include <cstdio>

int main(){
	int c0=0,c1=0;
	for(int i=0 ;i<3;i++){
		for(int j=0,a ; j<4; j++){
			scanf("%d",&a);
			a ? c1++ : c0++;
		}
		if(c0==1) printf("A\n");
		if(c0==2) printf("B\n");
		if(c0==3) printf("C\n");
		if(c0==4) printf("D\n");
		if(c1==4) printf("E\n");
		c1=c0=0;
	}
	return 0;
}