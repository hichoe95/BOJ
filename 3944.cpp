#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int b,a=0;
		cin >> b;
		getchar();
		while(1){
			char c = getchar();
			if(c == '\n') break;
			a = (a*b + c-'0') % (b-1);
		}
		cout << a << '\n';
	}
}
