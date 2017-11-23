#include <cstdio>

int N,S,c;
int a[20];

void ks(int i, int s){
	
	if(i>=N) return;

	if(i==N-1 && s == S){
		c++;
		return;
	}

	ks(i+1,s+a[i+1]);
	ks(i+1,s);
}

int main(){

	scanf("%d %d",&N,&S);

	for(int i=0 ; i<N ; i++) scanf("%d",&a[i]);

	ks(0,a[0]),ks(0,0);
	if(!S) c-=1;
	printf("%d",c);

	return 0;
}