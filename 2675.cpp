#include <iostream>
#include <string>
using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int len = s.length();
		for(int i=0 ;i<len;i++)
			for(int j=0 ; j<n ; j++)
				cout << s[i];
		cout << '\n';
	}

	return 0;
}