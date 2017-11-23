#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	long long N;
	int arr[20]={0,},i=0;

	scanf("%lld",&N);

	while(N){
		arr[i] = N%10;
		N/=10;
		i++;
	}
	sort(arr,arr+i);
	reverse(arr,arr+i);
	for(int j=0 ;j<i;j++) printf("%d",arr[j]);
	return 0;
}