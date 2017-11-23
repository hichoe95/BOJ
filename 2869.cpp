#include <cstdio>

int main(){
	long long a, b, v;
	scanf("%lld %lld %lld",&a,&b,&v);


	printf("%lld\n",1 + ((v-a)%(a-b) ? ((v-a)/(a-b) +1) : (v-a)/(a-b)));
	return 0;
}