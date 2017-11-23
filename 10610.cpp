#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

	string s;
	cin >> s;
	sort(s.begin(),s.end());

	int sum=0;
	for(char c : s) sum+=c-'0';


	if(sum%3 == 0 && s[0] == '0'){
		reverse(s.begin(),s.end());
		cout << s << '\n';
	}
	else{
		cout << -1 << '\n';
	}
	return 0;
}