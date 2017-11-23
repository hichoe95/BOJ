#include <cstdio>

int g(int x,int y){
	return x?g(y%x,x):y;
}
int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	printf("%d\n",x+y-g(x,y));
	return 0;
}
