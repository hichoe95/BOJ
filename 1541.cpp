#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

	string s;
	cin >> s;

	int n = s.length();
	vector<int> num;
	int start,temp=0,index;
	int ans=0;
	for(int i=0 ;i<n;i++)
		if(s[i] == '-'){
			start = i;
			break;
		}

	for(int i=0 ;i<n;i++){
		if(s[i] == '-' || s[i] == '+'){
			num.push_back(temp);
			if(i == start) index = num.size();
			temp = 0;
		}
		else{
			temp  = temp * 10 + s[i]-'0';
		}
		if(i==n-1) num.push_back(temp);
	}

	for(int i=0 ; i <num.size() ; i++){
		if(i<index) ans+=num[i];
		else ans -=num[i];
	}

	cout << ans << '\n';

	return 0;
}