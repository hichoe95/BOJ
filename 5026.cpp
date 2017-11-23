#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	while(N--){
		string s;
		cin >> s;
		int a=0,b=0,i=0;
		if(s=="P=NP") cout << "skipped\n";
		else{
			while(s[i]!='+') a*=10,a+=(s[i]-'0'),i++;
			i+=1;
			while(s[i]) b*=10,b+=(s[i]-'0'),i++;
			cout << a+b << '\n';
		}
	}
	return 0;
}