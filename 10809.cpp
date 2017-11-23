#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(){
	int n[26],len;
	memset(n,-1,sizeof(n));
	string s;
	cin >> s;
	len = s.length();
	for(int i=0 ;i<len ; i++){
		int & t = n[s[i]-'a'];
		if(t==-1)
			t = i;
	}
	for(int i=0 ;i<26 ; i++) printf("%d ",n[i]);
	return 0;
}