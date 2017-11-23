#include <cstdio>
#define ll long long 

int main(){
	int t;
	scanf("%d",&t);
	while(t--){

		int n;
		scanf("%d",&n);

		ll d[65][10]={0,};
		for(int i=0 ;i<10 ;i++) d[0][i] = 1,d[1][i] = 10-i;

		for(int i=2 ;i<n;i++){
			for(int j=0 ; j<10 ; j++){
				ll sum =0 ;
				for(int k=j ; k<10;k++) sum += d[i-1][k];
				d[i][j] = sum;
			}
		}
		ll sum = 0;
		for(int i=0 ;i<10 ;i++) sum+=d[n-1][i];
		printf("%lld\n",sum);
	}
	return 0;
}