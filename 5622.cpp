#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	string s;
	cin >> s;
	int len = s.length(),sum = 0;

	for(int i=0 ; i<len ; i++){
		char & S = s[i];
		if(S-'A' >=22) sum+=9;
		else if(S-'A' >= 19) sum+= 8;
		else if(S-'A' >= 15) sum+= 7;
		else if(S-'A' >= 12) sum+= 6;
		else if(S-'A' >= 9) sum+= 5;
		else if(S-'A' >= 6) sum+= 4;
		else if(S-'A' >= 3) sum+= 3;
		else sum+= 2;
	}
	cout << sum+len << '\n';

	return 0;
}