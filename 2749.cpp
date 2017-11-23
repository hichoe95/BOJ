#include <iostream>
using namespace std;

int main(){

	long long a,b,c,n;

	cin >> n;
	a=0,b=1;
	for(int i=0 ;i<n-1;i++){
		c = (a+b)%1000000;
		a=b,b=c;
	}

	cout << c << endl;

	return 0;
}