#include <cstdio>
#include <cmath>

int max(int a){
	int ret=0,i=0;

	while(a){
		if((a%10) == 5) ret += 6*(int)pow(10,i);
		else ret+=(a%10) * (int)pow(10,i);
		a/=10,i++;
	}
	return ret;
}

int min(int a){
	int ret=0,i=0;

	while(a){
		if((a%10) == 6) ret += 5*(int)pow(10,i);
		else ret+=(a%10) * (int)pow(10,i);
		a/=10,i++;
	}
	return ret;
}

int main(){

	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d %d\n",min(a)+min(b),max(a)+max(b));
	return 0;
}