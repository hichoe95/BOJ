#include <cstdio>
#include <algorithm>
using namespace std;


int main(){

	int n,t[100001]={0,},day=-1;

	scanf("%d",&n);
	for(int i=1 ;i<=n;i++) scanf("%d",&t[i]);

	sort(t+1,t+n+1);
	reverse(t+1,t+n+1);

	for(int i=1 ; i<=n; i++)
		if(i+t[i]>day)
			day = i+t[i];


	printf("%d\n",day+1);

	return 0;
}