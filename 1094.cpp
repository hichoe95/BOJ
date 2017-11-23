#include <iostream>
using namespace std;

int main(){
	int x,cnt=0;
	cin >> x;
	while(x){
		if(x&1) cnt++;
		x>>=1;
	}
	cout << cnt << '\n';
	return 0;
}