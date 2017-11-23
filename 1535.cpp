#include <iostream>
using namespace std;
#define max(a,b) a>b ? a : b

int n,L[21],J[21],MAX=0;

void find_max(int a,int hp,int M){

	if(hp >= 100) return;
	
	MAX = max(MAX,M);

	for(int i=a+1 ; i<n;i++) find_max(i,hp + L[i],M + J[i]);
}

int main(){

	ios_base::sync_with_stdio(false);
	
	cin >> n;

	for(int i=0 ;i<n;i++) cin >> L[i];
	for(int i=0 ;i<n;i++) cin >> J[i];

	for(int i=0 ;i<n;i++){
		find_max(i,L[i],J[i]);
	}

	cout << MAX << '\n';

	return 0;
}