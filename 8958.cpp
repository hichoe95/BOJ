#include <iostream>
#include <cstring>
using namespace std;

int main(){

	int t;
	cin >> t;
	while(t--){
		string c;
		cin >> c;

		int strlen = c.length(),k=1,sum=0;
		for(int i=0 ;i<strlen ; i++)
			c[i]=='O' ? sum+=(k++) : k=1;

		cout << sum << '\n';
	}

	return 0;
}