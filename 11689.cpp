#include <cstdio>
#define ll long long

ll phi(ll n){
	ll res = n;

	for(ll i=2;i*i<=n;i++){
		if(!(n%i)){
			while(!(n%i)) n/=i;
			res -= res/i;
		}
	}
	if(n>1) res -= res/n;
	return res;
}

int main(){
	ll n;
	scanf("%lld",&n);
	printf("%lld\n",phi(n));
	return 0;
}










