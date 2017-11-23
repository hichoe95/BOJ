#include <cstdio>
#include <cstring>

int digit[6];

int check(){

	int k=0;
	int d = digit[k] - digit[k+1];
	while(digit[k+1]!=-1){
		if((digit[k]-digit[k+1])!=d){
			return 0;
		}
		k++;
	}

	return 1;
}

int main(){

	int a,sum=0;
	scanf("%d",&a);

	for(int i=1 ; i<=a ; i++){
		memset(digit,-1,sizeof(digit));
		int d = 0,n=i;
		while(n){
			digit[d] = n%10;
			n/=10;
			d++;
		}
		sum += check();
	}

	printf("%d",sum);

	return 0;
}