#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

	int n,m,k;
	cin >> n >> m >> k;
	int team=0;
	while(1){
		if(n-2>=0 && m-1>=0){
			n-=2;
			m-=1;
		}
		else break;
		if(n+m>=k) team++;
		else break;
	}

	cout << team << '\n';

	return 0;
}