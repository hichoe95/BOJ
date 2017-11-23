#include <cstdio>
#include <algorithm>
using namespace std;

int N,M,arr[5000];

bool check(int s){

	int mini = arr[0],maxi = arr[0],section=1;

	for(int i= 1; i<N; i++){
		mini = min(mini,arr[i]);
		maxi = max(maxi,arr[i]);
		if(maxi - mini > s) mini = maxi = arr[i],section++;
	}
	return section<=M;
}

int main(){

	scanf("%d%d",&N,&M);

	for(int i=0 ;i<N ;i++) scanf("%d",&arr[i]);

	int L=0,R=9999,C;
	
	while(L<=R){
		C = (L+R)/2;
		check(C) ? (R = C-1) : (L = C+1);
	}

	printf("%d\n",L);

	
	return 0;
}