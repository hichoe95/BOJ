#include <iostream>
using namespace std;

#define MOD 14579

int sum(int n){
	return (n*(n+1)/2)%MOD;
}

int main(){

	int a,b;
	long long ans=1;
	cin >> a >> b;

	for(int i = a ; i<=b ; i++){
		ans*=sum(i);
		ans%=MOD;
	}

	cout << ans << '\n';

	return 0;
}