#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;
		int len = s.length();

		if(len&1) s+=s, len = s.length();
		
		for(int j=0 ; j<2 ; j++){
			for(int i = j ; i<len ; i+=2) cout << s[i];
			cout << '\n';
		}
	}

	return 0;
}